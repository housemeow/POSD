#include "stdafx.h"
#include "undo_state.h"
#include "menu_state.h"


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
        _textUIView.printMindMap(_mindMapModel->getMindMap());
    } catch (exception exception) {
        _textUIView.printException(exception);
    }
    return new MenuState(_mindMapModel);
}