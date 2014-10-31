#include "stdafx.h"
#include "mind_map_model.h"
#include "component_factory.h"
#include "command.h"

using namespace std;

MindMapModel::MindMapModel()
{
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
    _mindMap = factory.createComponent(ComponentType::ComponentTypeRoot, _currentId++);
    _mindMap->setDescription(mindMapName);
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
                component->addSibling(node);
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
    Component* newNode = componentFactory.createComponent(componentType, _currentId++);
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
void MindMapModel::saveMindMap()
{
    ofstream file;
    file.open("file__exist.mm");
    ComponentFactory componentFactory;
    Component* saveMindMap = componentFactory.copyMindMap(_mindMap);
    int newId = 0;
    for (int id = 0; id < _currentId; id++) {
        Component* component = saveMindMap->findNode(id);
        if (component) {
            component->setId(newId++);
        }
    }
    for (int id = 0; id < _currentId; id++) {
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
    file.close();
}

void MindMapModel::loadMindMap(string filePath)
{
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
        _currentId = id + 1;
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
    if (_mindMap != NULL) {
        delete _mindMap;
    }
    _mindMap = findComponent(components, 0);
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

// 取得當前的MindMap根節點
Component* MindMapModel::getMindMap()
{
    return _mindMap;
}