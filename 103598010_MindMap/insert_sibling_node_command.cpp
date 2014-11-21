#include "stdafx.h"
#include "mind_map_model.h"
#include "insert_sibling_node_command.h"


InsertSiblingNodeCommand::InsertSiblingNodeCommand(MindMapModel* mindMapModel, Component* component, string description)
{
    _component = component;
    _description = description;
    _mindMapModel = mindMapModel;
}


InsertSiblingNodeCommand::~InsertSiblingNodeCommand()
{
}

void InsertSiblingNodeCommand::execute()
{
    _mindMapModel->insertSiblingNode(_component, _description);
}

void InsertSiblingNodeCommand::unexecute()
{
    _siblingComponent->setParent(NULL);
    delete _siblingComponent;
}

