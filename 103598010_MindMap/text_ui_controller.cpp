#include "stdafx.h"
#include "text_ui_controller.h"
#include "mind_map_model.h"
#include "component_factory.h"
#include "text_ui_state.h"
#include "menu_state.h"

using namespace std;

TextUIController::TextUIController(MindMapModel* mindMapModel)
{
    _mindMapModel = mindMapModel;
}

TextUIController::~TextUIController()
{
}

void TextUIController::run()
{
    TextUIState* state = new MenuState(_mindMapModel);
    do {
        TextUIState* nextState = state->run();
        delete state;
        state = nextState;
        TextUIView textUIView;
        textUIView.printLine("");
    } while(state != NULL);
}