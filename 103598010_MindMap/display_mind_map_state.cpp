#include "stdafx.h"
#include "display_mind_map_state.h"
#include "menu_state.h"

DisplayMindMapState::DisplayMindMapState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


DisplayMindMapState::~DisplayMindMapState()
{
}


TextUIState* DisplayMindMapState::run()
{
    if (_mindMapModel->getMindMap() != NULL) {
        _textUIView.printMindMap(_mindMapModel->getMindMap());
    } else {
        _textUIView.printMindMapNotExist();
    }
    return new MenuState(_mindMapModel);
}