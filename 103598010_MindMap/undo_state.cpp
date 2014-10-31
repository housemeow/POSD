#include "stdafx.h"
#include "undo_state.h"
#include "text_ui_state_factory.h"


UndoState::UndoState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


UndoState::~UndoState()
{
}


TextUIState* UndoState::run()
{
    try {
        _mindMapModel->undo();
        _textUIView->printMindMap(_mindMapModel->getMindMap());
    } catch (exception exception) {
        _textUIView->printException(exception);
    }
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}