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
    _mindMapModel->insertChildNodeCommand(_component, description);
    _textUIView->printMindMap(_mindMapModel->getMindMap());
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}