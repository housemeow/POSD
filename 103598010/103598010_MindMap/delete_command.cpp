#include "stdafx.h"
#include "delete_command.h"
#include "component_factory.h"
#include "mind_map_model.h"

DeleteCommand::DeleteCommand(Component* component)
{
    _component = component;
    _mindMap = component->getMindMap();
    _parentComponent = component->getParent();
    _id = component->getId();
    _description = component->getDescription();
    Component* originParentComponent = component->getParent();
    list<Component*> parentComponentChildren = originParentComponent->getNodeList();
    list<Component*>::iterator componentIterator;
    for (componentIterator = parentComponentChildren.begin(); *componentIterator != component; ++componentIterator);
    _originPosition = distance(parentComponentChildren.begin(), componentIterator);
    list<Component*> children = component->getNodeList();
    for (componentIterator = children.begin(); componentIterator != children.end(); ++componentIterator) {
        _childrenId.push_back((*componentIterator)->getId());
    }
}


DeleteCommand::~DeleteCommand()
{
}

void DeleteCommand::execute()
{
    if (_component == _mindMap) {
        throw exception("You cannot delete root!");
    }
    list<Component*> children = _component->getNodeList();
    for (list<Component*>::const_iterator componentIterator = children.begin(); componentIterator != children.end(); ++componentIterator) {
        Component* child = *componentIterator;
        _component->getParent()->addChild(child);
    }
    _component->setParent(NULL);
    delete _component;
}

void DeleteCommand::unexecute()
{
    ComponentFactory componentFactory;
    _component = componentFactory.createComponent(ComponentTypeNode, _id);
    _component->setDescription(_description);
    for (list<int>::const_iterator componentIterator = _childrenId.begin(); componentIterator != _childrenId.end(); ++componentIterator) {
        int id = *componentIterator;
        Component* childComponent = _mindMap->findNode(id);
        childComponent->setParent(NULL);
        _component->addChild(childComponent);
    }
    // add to origin position
    list<Component*>& originParentComponentChildren = _parentComponent->getNodeList();
    std::list<Component*>::iterator originPosition = originParentComponentChildren.begin();
    std::advance(originPosition, _originPosition);
    originParentComponentChildren.insert(originPosition, _component);
    _component->setParent(_parentComponent);
}
