#include "stdafx.h"
#include "insert_child_node_state.h"
#include "text_ui_state_factory.h"
#include "insert_child_node_command.h"

InsertChildNodeState::InsertChildNodeState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}


InsertChildNodeState::~InsertChildNodeState()
{
}

TextUIState* InsertChildNodeState::run()
{
    string description;
    description = readLineString();
    InsertChildNodeCommand* insertChildNodeCommand = new InsertChildNodeCommand(_mindMapModel, _component, description);
    _mindMapModel->execute(insertChildNodeCommand);
    _textUIView->printMindMap(_mindMapModel->getMindMap());
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}