#include "stdafx.h"
#include "edit_state.h"
#include "menu_state.h"

EditState::EditState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


EditState::~EditState()
{
}

TextUIState* EditState::run()
{
    cout << "EditState\n";
    return new MenuState(_mindMapModel);
}