#include "stdafx.h"
#include "display_mind_map_state.h"
#include "text_ui_state_factory.h"

DisplayMindMapState::DisplayMindMapState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


DisplayMindMapState::~DisplayMindMapState()
{
}


TextUIState* DisplayMindMapState::run()
{
    if (_mindMapModel->getMindMap() != NULL) {
        _textUIView->printMindMap(_mindMapModel->getMindMap());
    } else {
        _textUIView->printMindMapNotExist();
    }
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}