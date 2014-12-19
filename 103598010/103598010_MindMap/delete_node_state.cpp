#include "stdafx.h"
#include "delete_node_state.h"
#include "text_ui_state_factory.h"

DeleteNodeState::DeleteNodeState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}


DeleteNodeState::~DeleteNodeState()
{
}

TextUIState* DeleteNodeState::run()
{
    if (_component == _mindMapModel->getMindMap()) {
        _textUIView->printCannotDeleteRoot();
    } else {
        _mindMapModel->deleteComponentCommand(_component);
        _textUIView->printMindMap(_mindMapModel->getMindMap());
    }
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}