#include "stdafx.h"
#include "load_state.h"
#include "menu_state.h"


LoadState::LoadState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


LoadState::~LoadState()
{
}


TextUIState* LoadState::run()
{
    cout << "LoadState\n";
    return new MenuState(_mindMapModel);
}