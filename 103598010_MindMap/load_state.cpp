#include "stdafx.h"
#include "load_state.h"
#include "menu_state.h"


LoadState::LoadState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


LoadState::~LoadState()
{
}


TextUIState* LoadState::run()
{
    _textUIView.printEnterFilePath();
    string filePath = readLineString();
    try {
        _mindMapModel->loadMindMap(filePath);
        _textUIView.printMindMap(_mindMapModel->getMindMap());
    } catch (exception exception) {
        _textUIView.printException(exception);
    }
    return new MenuState(_mindMapModel);
}