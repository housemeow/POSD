#include "stdafx.h"
#include "insert_parent_node_state.h"
#include "text_ui_state_factory.h"
#include "insert_parent_node_command.h"

InsertParentNodeState::InsertParentNodeState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}


InsertParentNodeState::~InsertParentNodeState()
{
}

TextUIState* InsertParentNodeState::run()
{
    string description;
    description = readLineString();
    _mindMapModel->insertNewNode(_component, description, InsertNodeModeParent);
    _textUIView.printMindMap(_mindMapModel->getMindMap());
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}