#pragma once
#include "text_ui_state.h"
#include "mind_map_model.h"

class CreateMindMapState :
    public TextUIState
{
public:
    CreateMindMapState(MindMapModel* mindMapModel);
    ~CreateMindMapState();
    TextUIState* run();
};

