#pragma once
#include "text_ui_state.h"
class EditDescriptionState :
    public TextUIState
{
public:
    EditDescriptionState(MindMapModel* mindMapModel, Component* component);
    ~EditDescriptionState();
    TextUIState* run();
private :
    Component* _component;
};

