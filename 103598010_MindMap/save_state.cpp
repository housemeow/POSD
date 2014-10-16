#include "stdafx.h"
#include "save_state.h"
#include "menu_state.h"

SaveState::SaveState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


SaveState::~SaveState()
{
}

TextUIState* SaveState::run()
{
    if (_mindMapModel->getMindMap()) {
        _mindMapModel->saveMindMap();
        _textUIView.printSaveMindMapSuccess();
    } else {
        _textUIView.printMindMapNotExist();
    }
    return new MenuState(_mindMapModel);
}