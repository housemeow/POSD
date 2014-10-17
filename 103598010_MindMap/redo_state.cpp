#include "stdafx.h"
#include "redo_state.h"
#include "menu_state.h"


RedoState::RedoState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


RedoState::~RedoState()
{
}

TextUIState* RedoState::run()
{
    try {
        _mindMapModel->redo();
        _textUIView.printMindMap(_mindMapModel->getMindMap());
    } catch (exception exception) {
        _textUIView.printException(exception);
    }
    return new MenuState(_mindMapModel);
}
