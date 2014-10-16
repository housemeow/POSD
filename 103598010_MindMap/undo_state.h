#pragma once
#include "text_ui_state.h"
class UndoState :
    public TextUIState
{
public:
    UndoState(MindMapModel* mindMapModel);
    ~UndoState();
    TextUIState* run();
};

