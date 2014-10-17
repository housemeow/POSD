#include "stdafx.h"
#include "delete_node_state.h"
#include "menu_state.h"
#include "delete_command.h"

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
        _textUIView.printCannotDeleteRoot();
    } else {
        DeleteCommand* deleteCommand = new DeleteCommand(_component);
        _mindMapModel->execute(deleteCommand);
        _textUIView.printMindMap(_mindMapModel->getMindMap());
    }
    return new MenuState(_mindMapModel);
}