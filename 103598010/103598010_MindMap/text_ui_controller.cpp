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
    _istream = &cin;
}

TextUIController::~TextUIController()
{
}

void TextUIController::setIStream(istream* istream)
{
    _istream = istream;
}

void TextUIController::run()
{
    TextUIState* state = new MenuState(_mindMapModel);
    do {
        state->setTextUIView(_textUIView);
        state->setIStream(_istream);
        TextUIState* nextState = state->run();
        delete state;
        state = nextState;
        TextUIView textUIView(cout);
        textUIView.printLine("");
    } while(state != NULL);
}