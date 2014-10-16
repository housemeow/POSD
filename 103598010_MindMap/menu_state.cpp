#include "stdafx.h"
#include "menu_state.h"
#include "text_ui_view.h"
#include "exit_state.h"

MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}


TextUIState* MenuState::run()
{
    TextUIView view;
    view.printMenu();
    int value;
    cin >> value;
    if (value == 5) {
        return new ExitState();
    }
    return new MenuState();
}