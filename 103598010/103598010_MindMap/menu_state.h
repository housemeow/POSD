#pragma once
#include "text_ui_state.h"
class MenuState :
    public TextUIState
{
public:
    static const int TEXT_UI_CREATE_MIND_MAP_INSTRUCTION;
    static const int TEXT_UI_INSERT_NODE_INSTRUCTION;
    static const int TEXT_UI_EDIT_NODE_INSTRUCTION;
    static const int TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION;
    static const int TEXT_UI_SAVE_MIND_MAP_INSTRUCTION;
    static const int TEXT_UI_LOAD_MIND_MAP_INSTRUCTION;
    static const int TEXT_UI_REDO_INSTRUCTION;
    static const int TEXT_UI_UNDO_INSTRUCTION;
    static const int TEXT_UI_EXIT_INSTRUCTION;
    MenuState(MindMapModel* mindMapModel);
    ~MenuState();
    TextUIState* run();
};

