#include "stdafx.h"
#include "change_parent_command.h"


ChangeParentCommand::ChangeParentCommand(Component* component, Component* parentComponent)
{
    _component = component;
    _parentComponent = parentComponent;
    _originParentComponent = component->getParent();
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
    _parentComponent->addChild(_component);
}

void ChangeParentCommand::unexecute()
{
    list<Component*> children = _component->getNodeList();
    for (list<Component*>::const_iterator componentIterator = _children.begin(); componentIterator != _children.end(); ++componentIterator) {
        _component->addChild(*componentIterator);
    }
    _originParentComponent->addChild(_component);
}
