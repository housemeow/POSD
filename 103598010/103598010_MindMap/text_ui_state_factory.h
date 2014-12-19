#pragma once
#include "text_ui_state.h"

enum TextUIStateEnum;

class TextUIStateFactory
{
public:
    TextUIStateFactory();
    ~TextUIStateFactory();
    static TextUIState* createTextUIState(TextUIStateEnum textUIState, MindMapModel* mindMapModel, Component* component = NULL);
};

enum TextUIStateEnum {
    MenuStateInstruction,
    CreateMindMapStateInstruction,
    InsertMenuStateInstruction,
    InsertParentNodeStateInstruction,
    InsertChildNodeStateInstruction,
    InsertSiblingNodeStateInstruction,
    EditMenuStateInstruction,
    EditDescriptionStateInstruction,
    ChangeParentStateInstruction,
    DeleteNodeStateInstruction,
    DisplayMindMapStateInstruction,
    SaveStateInstruction,
    LoadStateInstruction,
    RedoStateInstruction,
    UndoStateInstruction,
    ExitStateInstruction
};
