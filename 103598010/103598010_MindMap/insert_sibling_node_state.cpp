#include "stdafx.h"
#include "insert_sibling_node_state.h"
#include "text_ui_state_factory.h"

InsertSiblingNodeState::InsertSiblingNodeState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}

InsertSiblingNodeState::~InsertSiblingNodeState()
{
}

TextUIState* InsertSiblingNodeState::run()
{
    string description;
    description = readLineString();
    _mindMapModel->insertSiblingNodeCommand(_component, description);
    _textUIView->printMindMap(_mindMapModel->getMindMap());
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}