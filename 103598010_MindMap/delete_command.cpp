#include "stdafx.h"
#include "delete_command.h"
#include "component_factory.h"

DeleteCommand::DeleteCommand(Component* component)
{
    _component = component;
    _parentComponent = component->getParent();
    _id = component->getId();
    _description = component->getDescription();
    list<Component*> children = component->getNodeList();
    _children.insert(_children.end(), children.begin(), children.end());
}


DeleteCommand::~DeleteCommand()
{
}

void DeleteCommand::execute()
{
    for (list<Component*>::const_iterator componentIterator = _children.begin(); componentIterator != _children.end(); ++componentIterator) {
        _component->getParent()->addChild(*componentIterator);
    }
    _component->setParent(NULL);
    delete _component;
}

void DeleteCommand::unexecute()
{
    ComponentFactory componentFactory;
    _component = componentFactory.createComponent(ComponentTypeNode, _id);
    _component->setDescription(_description);
    _parentComponent->addChild(_component);
    for (list<Component*>::const_iterator componentIterator = _children.begin(); componentIterator != _children.end(); ++componentIterator) {
        _component->addChild(*componentIterator);
    }
}
