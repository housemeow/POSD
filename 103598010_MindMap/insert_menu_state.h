#pragma once
#include "text_ui_state.h"
class InsertMenuState :
    public TextUIState
{
public:
    InsertMenuState(MindMapModel* mindMapModel);
    ~InsertMenuState();
    TextUIState* run();
};

