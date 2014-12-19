#pragma once
#include "text_ui_state.h"
class DeleteNodeState :
    public TextUIState
{
public:
    DeleteNodeState(MindMapModel* mindMapModel, Component* component);
    ~DeleteNodeState();
    TextUIState* run();
private:
    Component* _component;
};

