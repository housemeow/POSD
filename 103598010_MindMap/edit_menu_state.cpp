#include "stdafx.h"
#include "edit_menu_state.h"
#include "text_ui_state_factory.h"

const int TEXT_UI_EDIT_DESCRIPTION_INSTRUCTION = 'a';
const int TEXT_UI_CHANGE_PARENT_INSTRUCTION = 'b';
const int TEXT_UI_DELETE_NODE_INSTRUCTION = 'c';

EditMenuState::EditMenuState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


EditMenuState::~EditMenuState()
{
}

TextUIState* EditMenuState::run()
{
    if (_mindMapModel->getMindMap() == NULL) {
        _textUIView.printMindMapNotExist();
        return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
    }
    _textUIView.printMindMap(_mindMapModel->getMindMap());
    int id;
    _textUIView.printEnterEditNodeIDMessage();
    id = readInt();
    Component* component = _mindMapModel->getMindMap()->findNode(id);
    if (component) {
        char instruction;
        while (true) {
            _textUIView.printEditMenu();
            instruction = readChar();
            switch (instruction) {
                case TEXT_UI_EDIT_DESCRIPTION_INSTRUCTION:
                    return TextUIStateFactory::createTextUIState(EditDescriptionStateInstruction, _mindMapModel, component);
                    break;
                case TEXT_UI_CHANGE_PARENT_INSTRUCTION:
                    return TextUIStateFactory::createTextUIState(ChangeParentStateInstruction, _mindMapModel, component);
                    break;
                case TEXT_UI_DELETE_NODE_INSTRUCTION:
                    return TextUIStateFactory::createTextUIState(DeleteNodeStateInstruction, _mindMapModel, component);
                    break;
                default:
                    _textUIView.printCommandNotFound();
                    break;
            }
        }
    } else {
        _textUIView.printNodeIsNotExist();
        return new EditMenuState(_mindMapModel);
    }
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}