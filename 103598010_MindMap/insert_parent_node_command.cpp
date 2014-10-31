#include "stdafx.h"
#include "mind_map_model.h"
#include "insert_parent_node_command.h"

InsertParentNodeCommand::InsertParentNodeCommand(MindMapModel* mindMapModel, Component* component, string description)
{
    _component = component;
    _description = description;
    _mindMapModel = mindMapModel;
}

InsertParentNodeCommand::InsertParentNodeCommand()
{
}


InsertParentNodeCommand::~InsertParentNodeCommand()
{
}

void InsertParentNodeCommand::execute()
{
    _parentComponent = _mindMapModel->createNode(ComponentTypeNode, _description);
    _component->getParent()->addChild(_parentComponent);
    _component->addParent(_parentComponent);
}

void InsertParentNodeCommand::unexecute()
{
    _parentComponent->getParent()->addChild(_component);
    _parentComponent->setParent(NULL);
    delete _parentComponent;
}
