#pragma once
#include "text_ui_state.h"
class ChangeParentState :
    public TextUIState
{
public:
    ChangeParentState(MindMapModel* mindMapModel, Component* component);
    ~ChangeParentState();
    TextUIState* run();
private:
    Component* _component;
};

