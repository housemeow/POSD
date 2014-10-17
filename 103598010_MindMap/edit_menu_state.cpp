#include "stdafx.h"
#include "edit_menu_state.h"
#include "menu_state.h"
#include "edit_description_state.h"
#include "change_parent_state.h"
#include "delete_node_state.h"

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
                    return new EditDescriptionState(_mindMapModel, component);
                    break;
                case TEXT_UI_CHANGE_PARENT_INSTRUCTION:
                    return new ChangeParentState(_mindMapModel, component);
                    break;
                case TEXT_UI_DELETE_NODE_INSTRUCTION:
                    return new DeleteNodeState(_mindMapModel, component);
                    break;
                default:
                    _textUIView.printCommandNotFound();
                    break;
            }
        }
    } else {
        _textUIView.printNodeIsNotExist();
    }
    return new MenuState(_mindMapModel);
}