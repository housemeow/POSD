#pragma once
#include "text_ui_state.h"
class MenuState :
    public TextUIState
{
public:
    MenuState(MindMapModel* mindMapModel);
    ~MenuState();
    TextUIState* run();
};

