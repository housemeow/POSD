#pragma once
#include "text_ui_state.h"
class InsertParentNodeState :
    public TextUIState
{
public:
    InsertParentNodeState(MindMapModel* mindMapModel, Component* component);
    ~InsertParentNodeState();
    TextUIState* run();
private:
    Component* _component;
};

