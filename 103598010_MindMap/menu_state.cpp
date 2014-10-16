#include "stdafx.h"
#include "menu_state.h"
#include "exit_state.h"
#include "create_mind_map_state.h"
#include "insert_state.h"
#include "display_mind_map_state.h"
#include "save_state.h"

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
    if (instruction == TEXT_UI_CREATE_MIND_MAP_INSTRUCTION) {
        return new CreateMindMapState(_mindMapModel);
    } else if (instruction == TEXT_UI_INSERT_NODE_INSTRUCTION) {
        return new InsertState(_mindMapModel);
    } else if (instruction == TEXT_UI_DISPLAY_MIND_MAP_INSTRUCTION) {
        return new DisplayMindMapState(_mindMapModel);
    } else if (instruction == TEXT_UI_SAVE_MIND_MAP_INSTRUCTION) {
        return new SaveState(_mindMapModel);
    } else if (instruction == TEXT_UI_EXIT_INSTRUCTION) {
        return new ExitState(_mindMapModel);
    } else {
        _textUIView.printWrongMenuInstruction();
    }
    return new MenuState(_mindMapModel);
}