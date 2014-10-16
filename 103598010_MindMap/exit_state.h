#pragma once
#include "text_ui_state.h"
class ExitState :
    public TextUIState
{
public:
    ExitState();
    ~ExitState();
    TextUIState* run();
};

