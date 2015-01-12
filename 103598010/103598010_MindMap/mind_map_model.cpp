#include "stdafx.h"
#include "mind_map_model.h"
#include "component_factory.h"
#include "command.h"
#include "change_parent_command.h"
#include "delete_command.h"
#include "edit_description_command.h"
#include "insert_child_node_command.h"
#include "insert_parent_node_command.h"
#include "insert_sibling_node_command.h"
#include "save_visitor.h"
#include "rectangle_decorator.h"
#include "ellipse_decorator.h"
#include "triangle_decorator.h"

using namespace std;

MindMapModel::MindMapModel()
{
    ComponentFactory::resetCurrentId();
    _mindMap = NULL;
}

MindMapModel::~MindMapModel()
{
    delete _mindMap;
}

// 建立一個全新的MindMap
void MindMapModel::createMindMap(string mindMapName)
{
    if (_mindMap) {
        delete _mindMap;
    }
    ComponentFactory factory;
    _mindMap = factory.createComponent(ComponentType::ComponentTypeRoot);
    _mindMap->setDescription(mindMapName);
    _commandManager.clear();
}

// 嘗試加入一個空節點，如果不成功會拋出exception
void MindMapModel::tryInsertNewNode(Component* component, InsertNodeMode insertMode)
{
    insertNode(component, NULL, insertMode);
}

// 加入一個節點
Component* MindMapModel::insertNode(Component* component, Component* node, InsertNodeMode insertMode)
{
    try {
        switch (insertMode) {
            case InsertNodeMode::InsertNodeModeParent:
                component->addParent(node);
                break;
            case InsertNodeMode::InsertNodeModeChild:
                component->addChild(node);
                break;
            case InsertNodeMode::InsertNodeModeSibling:
                component->addSibling(node, component);
                break;
            default:
                break;
        }
    } catch (string exception) {
        throw exception;
    }
    return component;
}

Component* MindMapModel::createNode(ComponentType componentType, string description)
{
    ComponentFactory componentFactory;
    Component* newNode = componentFactory.createComponent(componentType);
    newNode->setDescription(description);
    return newNode;
}

// 建立並加入一個新結點
Component* MindMapModel::insertNewNode(Component* component, string description, InsertNodeMode insertMode)
{
    Component* newNode = createNode(ComponentType::ComponentTypeNode, description);
    return insertNode(component, newNode, insertMode);
}

// 將MindMap存檔
void MindMapModel::saveMindMap(string fileName)
{
    SaveVisitor saveVisitor(fileName);
    _mindMap->accept(&saveVisitor);
    /*   ofstream file(fileName, ofstream::out);
       if (!file) {
           throw exception("Path is invalid!!");
       }
       ComponentFactory componentFactory;
       Component* saveMindMap = componentFactory.copyMindMap(_mindMap);
       int newId = 0;
       int currentId = componentFactory.getCurrentId();
       for (int id = 0; id < currentId; id++) {
           Component* component = saveMindMap->findNode(id);
           if (component) {
               component->setId(newId++);
           }
       }
       for (int id = 0; id < currentId; id++) {
           Component* component = saveMindMap->findNode(id);
           if (component) {
               file << id << " \"" << component->getDescription() << "\"";
               for (ComponentIterator iterator = component->getNodeList().begin(), end = component->getNodeList().end(); iterator != end; ++iterator) {
                   Component* child = *iterator;
                   file << " " << child->getId();
               }
               file << endl;
           }
       }
       delete saveMindMap;
       file.close();*/
}

void MindMapModel::loadMindMap(string filePath)
{
    if (_mindMap != NULL) {
        delete _mindMap;
    }
    ifstream ifstream(filePath, ifstream::in);
    if (!ifstream) {
        throw exception("File not found!!");
    }
    string line;
    list<Component*> components;
    multimap<Component*, int> componentChildren;
    while (getline(ifstream, line)) {
        stringstream splitterStringStream(line);
        int id;
        string description;
        string childrenString;
        readComponentData(line, id, description, childrenString);
        ComponentFactory componentFactory;
        componentFactory.setCurrentId(id + 1);
        stringstream childrenStringStream(childrenString);
        ComponentFactory factory;
        int child;
        Component* component = factory.createComponent(getComponentType(id), id);
        component->setDescription(description);
        components.push_back(component);
        while (childrenStringStream >> child) {
            componentChildren.insert(std::pair<Component*, int>(component, child));
        }
    }
    for (list<Component*>::iterator componentIterator = components.begin(); componentIterator != components.end(); ++componentIterator) {
        for (multimap<Component*, int>::const_iterator mapIterator = componentChildren.begin(); mapIterator != componentChildren.end(); ++mapIterator)
            if (mapIterator->first == *componentIterator) {
                (*componentIterator)->addChild(findComponent(components, mapIterator->second));
            }
    }
    for (list<Component*>::iterator componentIterator = components.begin(); componentIterator != components.end(); ++componentIterator) {
        Component* component = *componentIterator;
        ComponentDecorator* componentDecorator = new EllipseDecorator(new TriangleDecorator(new RectangleDecorator(component)));
        if (component->getParent() != NULL) {
            component->getParent()->replace(component, componentDecorator);
        } else {
            _mindMap = componentDecorator;
        }
    }
    ifstream.close();
}

Component* MindMapModel::findComponent(list<Component*> components, int id)
{
    for (list<Component*>::iterator componentIterator = components.begin(); componentIterator != components.end(); ++componentIterator) {
        if ((*componentIterator)->getId() == id) {
            return *componentIterator;
        }
    }
    return NULL;
}

ComponentType MindMapModel::getComponentType(int id)
{
    if (id == 0) {
        return ComponentTypeRoot;
    } else {
        return ComponentTypeNode;
    }
}
void MindMapModel::undo()
{
    _commandManager.undo();
}

void MindMapModel::redo()
{
    _commandManager.redo();
}

void MindMapModel::execute(Command* command)
{
    _commandManager.execute(command);
}

void MindMapModel::readComponentData(string line, int& id, string& description, string& children)
{
    stringstream splitterStringStream(line);
    string idString;
    getline(splitterStringStream, idString, '\"');
    getline(splitterStringStream, description, '\"');
    getline(splitterStringStream, children, '\"');
    stringstream idStringStream(idString);
    idStringStream >> id;
}


void MindMapModel::changeParentCommand(Component* component, Component* parentComponent)
{
    execute(new ChangeParentCommand(component, parentComponent));
}

// 取得當前的MindMap根節點
Component* MindMapModel::getMindMap()
{
    return _mindMap;
}

void MindMapModel::editDescription(Component* component, string description)
{
    EditDescriptionCommand* editDescriptionCommand = new EditDescriptionCommand(component, description);
    execute(editDescriptionCommand);
}

void MindMapModel::deleteComponentCommand(Component* component)
{
    DeleteCommand* deleteCommand = new DeleteCommand(component);
    execute(deleteCommand);
    _commandManager.clearRedo();
}

void MindMapModel::deleteComponentTree(Component* component)
{
    if (component == _mindMap) {
        throw exception("You cannot delete root!");
    }
    list<Component*> children = component->getNodeList();
    for (list<Component*>::const_iterator componentIterator = children.begin(); componentIterator != children.end(); ++componentIterator) {
        Component* child = *componentIterator;
        deleteComponentTree(child);
    }
    component->setParent(NULL);
    component->getNodeList().clear();
    delete component;
}

void MindMapModel::insertChildNodeCommand(Component* component, string description)
{
    execute(new InsertChildNodeCommand(this, component, description));
    _commandManager.clearRedo();
}

Component* MindMapModel::insertChildNode(int componentId, string description)
{
    Component* component = _mindMap->findNode(componentId);
    Component* childComponent = createNode(ComponentTypeNode, description);
    component->addChild(childComponent);
    return childComponent;
}

void MindMapModel::insertSiblingNodeCommand(Component* component, string description)
{
    execute(new InsertSiblingNodeCommand(this, component, description));
    _commandManager.clearRedo();
}

Component* MindMapModel::insertSiblingNode(Component* component, string description)
{
    if (component == _mindMap) {
        throw exception("Root cannot insert sibling!");
    }
    Component* siblingComponent = createNode(ComponentTypeNode, description);
    component->addSibling(siblingComponent, component);
    return siblingComponent;
}

void MindMapModel::insertParentNodeCommand(Component* component, string description)
{
    execute(new InsertParentNodeCommand(this, component, description));
    _commandManager.clearRedo();
}

void MindMapModel::insertParentNode(Component* component, string description)
{
    if (component == _mindMap) {
        throw exception("Root cannot insert parent!");
    }
    Component* parentComponent = createNode(ComponentTypeNode, description);
    component->getParent()->addChild(parentComponent);
    component->addParent(parentComponent);
}

int MindMapModel::getUndoCount()
{
    return _commandManager.getUndoCount();
}

int MindMapModel::getRedoCount()
{
    return _commandManager.getRedoCount();
}