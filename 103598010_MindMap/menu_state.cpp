#include "stdafx.h"
#include "menu_state.h"
#include "exit_state.h"
#include "create_mindmap_state.h"
#include "insert_state.h"

MenuState::MenuState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


MenuState::~MenuState()
{
}


TextUIState* MenuState::run()
{
    _textUIView.printMenu();
    int value;
    cin >> value;
    if (value == 1) {
        return new CreateMindMapState(_mindMapModel);
    } else if (value == 2) {
        return new InsertState(_mindMapModel);
    } else if (value == 5) {
        return new ExitState(_mindMapModel);
    }
    return new MenuState(_mindMapModel);
}