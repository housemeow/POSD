#include "stdafx.h"
#include "save_state.h"
#include "text_ui_state_factory.h"

SaveState::SaveState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


SaveState::~SaveState()
{
}

TextUIState* SaveState::run()
{
    if (_mindMapModel->getMindMap()) {
        _mindMapModel->saveMindMap("file__exist.mm");
        _textUIView->printMindMap(_mindMapModel->getMindMap());
        _textUIView->printSaveMindMapSuccess();
    } else {
        _textUIView->printMindMapNotExist();
    }
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}