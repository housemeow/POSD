#pragma once
#include "text_ui_state.h"
class EditState :
    public TextUIState
{
public:
    EditState(MindMapModel* mindMapModel);
    ~EditState();
    TextUIState* run();
};

