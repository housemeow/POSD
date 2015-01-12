#include "stdafx.h"
#include "menu_state.h"
#include "text_ui_state_factory.h"

const int MenuState::TEXT_UI_CREATE_MIND_MAP_INSTRUCTION = 1;
const int MenuState::TEXT_UI_INSERT_NODE_INSTRUCTION = 2;
const int MenuState::TEXT_UI_EDIT_NODE_INSTRUCTION = 3;
const int MenuState::TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION = 4;
const int MenuState::TEXT_UI_SAVE_MIND_MAP_INSTRUCTION = 5;
const int MenuState::TEXT_UI_LOAD_MIND_MAP_INSTRUCTION = 6;
const int MenuState::TEXT_UI_REDO_INSTRUCTION = 7;
const int MenuState::TEXT_UI_UNDO_INSTRUCTION = 8;
const int MenuState::TEXT_UI_EXIT_INSTRUCTION = 9;

MenuState::MenuState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}

MenuState::~MenuState()
{
}

TextUIState* MenuState::run()
{
    _textUIView->printMenu();
    int instruction = readInt();
    switch (instruction) {
        case TEXT_UI_CREATE_MIND_MAP_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(CreateMindMapStateInstruction, _mindMapModel);
        case TEXT_UI_INSERT_NODE_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(InsertMenuStateInstruction, _mindMapModel);
        case TEXT_UI_EDIT_NODE_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(EditMenuStateInstruction, _mindMapModel);
        case TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(DisplayMindMapStateInstruction, _mindMapModel);
        case TEXT_UI_SAVE_MIND_MAP_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(SaveStateInstruction, _mindMapModel);
        case TEXT_UI_LOAD_MIND_MAP_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(LoadStateInstruction, _mindMapModel);
        case TEXT_UI_REDO_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(RedoStateInstruction, _mindMapModel);
        case TEXT_UI_UNDO_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(UndoStateInstruction, _mindMapModel);
        case TEXT_UI_EXIT_INSTRUCTION:
            return TextUIStateFactory::createTextUIState(ExitStateInstruction, _mindMapModel);
        default:
            _textUIView->printWrongMenuInstruction();
            return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
    }
}