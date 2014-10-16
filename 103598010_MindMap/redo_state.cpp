#include "stdafx.h"
#include "redo_state.h"
#include "menu_state.h"


RedoState::RedoState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


RedoState::~RedoState()
{
}

TextUIState* RedoState::run()
{
    cout << "RedoState\n";
    return new MenuState(_mindMapModel);
}
