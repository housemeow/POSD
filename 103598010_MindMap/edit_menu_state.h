#pragma once
#include "text_ui_state.h"
class EditMenuState :
    public TextUIState
{
public:
    EditMenuState(MindMapModel* mindMapModel);
    ~EditMenuState();
    TextUIState* run();
};

