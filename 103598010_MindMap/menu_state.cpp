#include "stdafx.h"
#include "menu_state.h"
#include "exit_state.h"
#include "create_mind_map_state.h"
#include "insert_state.h"
#include "display_mind_map_state.h"
#include "save_state.h"
#include "edit_state.h"
#include "load_state.h"
#include "undo_state.h"
#include "redo_state.h"

const int TEXT_UI_CREATE_MIND_MAP_INSTRUCTION = 1;
const int TEXT_UI_INSERT_NODE_INSTRUCTION = 2;
const int TEXT_UI_EDIT_NODE_INSTRUCTION = 3;
const int TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION = 4;
const int TEXT_UI_SAVE_MIND_MAP_INSTRUCTION = 5;
const int TEXT_UI_LOAD_MIND_MAP_INSTRUCTION = 6;
const int TEXT_UI_REDO_INSTRUCTION = 7;
const int TEXT_UI_UNDO_INSTRUCTION = 8;
const int TEXT_UI_EXIT_INSTRUCTION = 9;

MenuState::MenuState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}

MenuState::~MenuState()
{
}

TextUIState* MenuState::run()
{
    _textUIView.printMenu();
    int instruction = readInt();
    switch (instruction) {
        case TEXT_UI_CREATE_MIND_MAP_INSTRUCTION:
            return new CreateMindMapState(_mindMapModel);
            break;
        case TEXT_UI_INSERT_NODE_INSTRUCTION:
            return new InsertState(_mindMapModel);
            break;
        case TEXT_UI_EDIT_NODE_INSTRUCTION:
            return new EditState(_mindMapModel);
            break;
        case TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION:
            return new DisplayMindMapState(_mindMapModel);
            break;
        case TEXT_UI_SAVE_MIND_MAP_INSTRUCTION:
            return new SaveState(_mindMapModel);
            break;
        case TEXT_UI_LOAD_MIND_MAP_INSTRUCTION:
            return new LoadState(_mindMapModel);
            break;
        case TEXT_UI_REDO_INSTRUCTION:
            return new RedoState(_mindMapModel);
            break;
        case TEXT_UI_UNDO_INSTRUCTION:
            return new UndoState(_mindMapModel);
            break;
        case TEXT_UI_EXIT_INSTRUCTION:
            return new ExitState(_mindMapModel);
            break;
        default:
            _textUIView.printWrongMenuInstruction();
            return new MenuState(_mindMapModel);
    }
}