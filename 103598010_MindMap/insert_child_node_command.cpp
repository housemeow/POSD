#include "stdafx.h"
#include "mind_map_model.h"
#include "insert_child_node_command.h"
#include "component_factory.h"

InsertChildNodeCommand::InsertChildNodeCommand(MindMapModel* mindMapModel, Component* component, string description)
{
    _component = component;
    _description = description;
    _mindMapModel = mindMapModel;
}

InsertChildNodeCommand::InsertChildNodeCommand()
{
}


InsertChildNodeCommand::~InsertChildNodeCommand()
{
}

void InsertChildNodeCommand::execute()
{
    _mindMapModel->insertChildNode(_component, _description);
}

void InsertChildNodeCommand::unexecute()
{
    _childComponent->setParent(NULL);
    delete _childComponent;
}
