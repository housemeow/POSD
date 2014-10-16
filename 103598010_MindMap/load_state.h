#pragma once
#include "text_ui_state.h"
class LoadState :
    public TextUIState
{
public:
    LoadState(MindMapModel* mindMapModel);
    ~LoadState();
    TextUIState* run();
};

