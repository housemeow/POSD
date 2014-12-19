#pragma once
#include "text_ui_state.h"
class RedoState :
    public TextUIState
{
public:
    RedoState(MindMapModel* mindMapModel);
    ~RedoState();
    TextUIState* run();
};

