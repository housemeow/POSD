#include "stdafx.h"
#include "text_ui_controller.h"
#include "mind_map_model.h"
#include "component_factory.h"
#include "text_ui_state.h"
#include "menu_state.h"

using namespace std;

TextUIController::TextUIController(MindMapModel* mindMapModel, TextUIView* textUIView)
{
    _mindMapModel = mindMapModel;
    _textUIView = textUIView;
}

TextUIController::~TextUIController()
{
}

void TextUIController::run()
{
    TextUIState* state = new MenuState(_mindMapModel);
    do {
        state->setTextUIView(_textUIView);
        TextUIState* nextState = state->run();
        delete state;
        state = nextState;
        TextUIView textUIView(cout);
        textUIView.printLine("");
    } while(state != NULL);
}