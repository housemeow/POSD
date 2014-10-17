#include "stdafx.h"
#include "change_parent_command.h"
#include <iterator>


ChangeParentCommand::ChangeParentCommand(Component* component, Component* parentComponent)
{
    _component = component;
    _parentComponent = parentComponent;
    _originParentComponent = component->getParent();
    list<Component*> parentComponentChildren = _originParentComponent->getNodeList();
    list<Component*>::iterator componentIterator;
    for (componentIterator = parentComponentChildren.begin(); *componentIterator != component; ++componentIterator);
    _originPosition = distance(parentComponentChildren.begin(), componentIterator);
    if (component->isAncientOf(parentComponent)) {
        list<Component*> children = component->getNodeList();
        _children.insert(_children.end(), children.begin(), children.end());
    }
}


ChangeParentCommand::~ChangeParentCommand()
{
}

void ChangeParentCommand::execute()
{
    for (list<Component*>::const_iterator componentIterator = _children.begin(); componentIterator != _children.end(); ++componentIterator) {
        _component->getParent()->addChild(*componentIterator);
    }
    //    _parentComponent->addChild(_component);
    _component->setParent(NULL);
    _parentComponent->getNodeList().push_front(_component);
    _component->setParent(_parentComponent);
}

void ChangeParentCommand::unexecute()
{
    //list<Component*> children = _component->getNodeList();
    //for (list<Component*>::const_iterator componentIterator = _children.begin(); componentIterator != _children.end(); ++componentIterator) {
    //	_component->addChild(*componentIterator);
    //}
    //_originParentComponent->addChild(_component);
    for (list<Component*>::const_iterator componentIterator = _children.begin(); componentIterator != _children.end(); ++componentIterator) {
        _component->addChild(*componentIterator);
    }
    _component->setParent(NULL);
    list<Component*>& originParentComponentChildren = _originParentComponent->getNodeList();
    std::list<Component*>::iterator originPosition = originParentComponentChildren.begin();
    std::advance(originPosition, _originPosition);
    originParentComponentChildren.insert(originPosition, _component);
    _component->setParent(_originParentComponent);
}
