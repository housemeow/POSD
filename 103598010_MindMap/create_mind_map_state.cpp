#include "stdafx.h"
#include "create_mind_map_state.h"
#include "text_ui_state_factory.h"

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
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}