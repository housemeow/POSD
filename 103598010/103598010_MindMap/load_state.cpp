#include "stdafx.h"
#include "load_state.h"
#include "text_ui_state_factory.h"


LoadState::LoadState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


LoadState::~LoadState()
{
}


TextUIState* LoadState::run()
{
    _textUIView->printEnterFilePath();
    string filePath = readLineString();
    try {
        _mindMapModel->loadMindMap(filePath);
        _textUIView->printMindMap(_mindMapModel->getMindMap());
    } catch (exception exception) {
        _textUIView->printException(exception);
    }
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}