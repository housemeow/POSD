#pragma once
#include "text_ui_state.h"
class DisplayMindMapState :
    public TextUIState
{
public:
    DisplayMindMapState(MindMapModel* mindMapModel);
    ~DisplayMindMapState();
    TextUIState* run();
};

