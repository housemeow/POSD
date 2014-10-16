#pragma once
#include "text_ui_state.h"
class InsertState :
    public TextUIState
{
public:
    InsertState(MindMapModel* mindMapModel);
    ~InsertState();
    TextUIState* run();
};

