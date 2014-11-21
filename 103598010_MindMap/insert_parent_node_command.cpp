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
    _mindMapModel->insertParentNode(_component, _description);
}

void InsertParentNodeCommand::unexecute()
{
    Component* parentComponent = _component->getParent();
    parentComponent->getParent()->addChild(_component);
    parentComponent->setParent(NULL);
    delete parentComponent;
    //_parentComponent->getParent()->addChild(_component);
    //_parentComponent->setParent(NULL);
    //delete _parentComponent;
}
