#pragma once
#include "text_ui_state.h"
class ExitState :
    public TextUIState
{
public:
    ExitState(MindMapModel* mindMapModel);
    ~ExitState();
    TextUIState* run();
};

