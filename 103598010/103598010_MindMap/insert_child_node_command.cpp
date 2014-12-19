#include "stdafx.h"
#include "mind_map_model.h"
#include "insert_child_node_command.h"
#include "component_factory.h"

InsertChildNodeCommand::InsertChildNodeCommand(MindMapModel* mindMapModel, Component* component, string description)
{
    _componentId = component->getId();
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
    Component* childrenComponet = _mindMapModel->insertChildNode(_componentId, _description);
    _childComponentId =  childrenComponet->getId();
}

void InsertChildNodeCommand::unexecute()
{
    Component* childrenComponent = _mindMapModel->getMindMap()->findNode(_childComponentId);
    childrenComponent->setParent(NULL);
    delete childrenComponent;
}
