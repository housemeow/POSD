#include "stdafx.h"
#include "create_mind_map_state.h"
#include "mind_map_model.h"
#include "menu_state.h"

CreateMindMapState::CreateMindMapState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
    _mindMapModel = mindMapModel;
}


CreateMindMapState::~CreateMindMapState()
{
}

TextUIState* CreateMindMapState::run()
{
    string description;
    _textUIView.printCreateMindMapMessage();
    description = readLineString();
    _mindMapModel->createMindMap(description);
    _textUIView.printMindMap(_mindMapModel->getMindMap());
    return new MenuState(_mindMapModel);
}