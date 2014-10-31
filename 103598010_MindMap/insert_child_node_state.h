#pragma once
#include "text_ui_state.h"
class InsertChildNodeState :
    public TextUIState
{
public:
    InsertChildNodeState(MindMapModel* mindMapModel, Component* component);
    ~InsertChildNodeState();
    TextUIState* run();
private:
    Component* _component;
};

