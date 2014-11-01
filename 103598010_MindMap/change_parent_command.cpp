#include "stdafx.h"
#include "change_parent_command.h"
#include <iterator>


ChangeParentCommand::ChangeParentCommand(Component* component, Component* parentComponent)
{
    _component = component;
    _parentComponentId = parentComponent->getId();
    _originParentComponentId = component->getParent()->getId();
    _mindMap = component->getMindMap();
    list<Component*> parentComponentChildren = component->getParent()->getNodeList();
    list<Component*>::iterator componentIterator;
    for (componentIterator = parentComponentChildren.begin(); *componentIterator != component; ++componentIterator);
    _originPosition = distance(parentComponentChildren.begin(), componentIterator);
    if (component->isAncientOf(parentComponent)) {
        list<Component*> children = component->getNodeList();
        for (list<Component*>::iterator componentIterator = children.begin(); componentIterator != children.end(); ++componentIterator) {
            _childrenId.push_back((*componentIterator)->getId());
        }
    }
}


ChangeParentCommand::~ChangeParentCommand()
{
}

void ChangeParentCommand::execute()
{
    for (list<int>::const_iterator componentIdIterator = _childrenId.begin(); componentIdIterator != _childrenId.end(); ++componentIdIterator) {
        Component* component = _mindMap->findNode(*componentIdIterator);
        _component->getParent()->addChild(component);
    }
    //    _parentComponent->addChild(_component);
    _component->setParent(NULL);
    Component* parentComponent = _mindMap->findNode(_parentComponentId);
    parentComponent->getNodeList().push_front(_component);
    _component->setParent(parentComponent);
}

void ChangeParentCommand::unexecute()
{
    for (list<int>::const_iterator componentIdIterator = _childrenId.begin(); componentIdIterator != _childrenId.end(); ++componentIdIterator) {
        Component* component = _mindMap->findNode(*componentIdIterator);
        _component->addChild(component);
    }
    _component->setParent(NULL);
    Component* originParentComponent = _mindMap->findNode(_originParentComponentId);
    list<Component*>& originParentComponentChildren = originParentComponent->getNodeList();
    std::list<Component*>::iterator originPosition = originParentComponentChildren.begin();
    std::advance(originPosition, _originPosition);
    originParentComponentChildren.insert(originPosition, _component);
    _component->setParent(originParentComponent);
}
