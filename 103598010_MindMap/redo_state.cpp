#include "stdafx.h"
#include "redo_state.h"
#include "text_ui_state_factory.h"


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
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}
