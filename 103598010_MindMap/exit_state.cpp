#include "stdafx.h"
#include "exit_state.h"


ExitState::ExitState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


ExitState::~ExitState()
{
}

TextUIState* ExitState::run()
{
    return NULL;
}
