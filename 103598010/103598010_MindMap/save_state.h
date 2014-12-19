#pragma once
#include "text_ui_state.h"
class SaveState :
    public TextUIState
{
public:
    SaveState(MindMapModel* mindMapModel);
    ~SaveState();
    TextUIState* run();
};

