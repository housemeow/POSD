#include "stdafx.h"
#include "undo_state.h"
#include "menu_state.h"


UndoState::UndoState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


UndoState::~UndoState()
{
}


TextUIState* UndoState::run()
{
    cout << "UndoState\n";
    return new MenuState(_mindMapModel);
}