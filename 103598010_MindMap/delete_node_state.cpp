#include "stdafx.h"
#include "delete_node_state.h"
#include "menu_state.h"

DeleteNodeState::DeleteNodeState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
}


DeleteNodeState::~DeleteNodeState()
{
}

TextUIState* DeleteNodeState::run()
{
    cout << "delete node\n";
    return new MenuState(_mindMapModel);
}