#include "stdafx.h"
#include "edit_description_state.h"
#include "edit_description_command.h"
#include "text_ui_state_factory.h"

EditDescriptionState::EditDescriptionState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}


EditDescriptionState::~EditDescriptionState()
{
}


TextUIState* EditDescriptionState::run()
{
    _textUIView.printEnterDescription();
    string description = readLineString();
    EditDescriptionCommand* editDescriptionCommand = new EditDescriptionCommand(_component, description);
    _mindMapModel->execute(editDescriptionCommand);
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}