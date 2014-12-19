#pragma once
#include "text_ui_state.h"
class InsertSiblingNodeState :
    public TextUIState
{
public:
    InsertSiblingNodeState(MindMapModel* mindMapModel, Component* component);
    ~InsertSiblingNodeState();
    TextUIState* run();
private:
    Component* _component;
};

