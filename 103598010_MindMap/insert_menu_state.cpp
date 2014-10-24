#include "stdafx.h"
#include "insert_menu_state.h"
#include "text_ui_state_factory.h"
#include "component_factory.h"

InsertMenuState::InsertMenuState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


InsertMenuState::~InsertMenuState()
{
}

TextUIState* InsertMenuState::run()
{
    if (!_mindMapModel->getMindMap()) {
        _textUIView.printMindMapNotExist();
        return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
    }
    _textUIView.printMindMap(_mindMapModel->getMindMap());
    int id;
    Component* component = NULL;
    while (component == NULL) {
        _textUIView.printEnterNodeIDMessage();
        id = readInt();
        component = _mindMapModel->getMindMap()->findNode(id);
    }
    ComponentFactory factory;
    bool continueInput = true;
    while (continueInput) {
        _textUIView.printInsertNewNodeMenu();
        char instruction;
        cin >> instruction;
        try {
            InsertNodeMode instructionEnum = (InsertNodeMode)instruction;
            if (instructionEnum != InsertNodeModeParent &&
                    instructionEnum != InsertNodeModeChild &&
                    instructionEnum != InsertNodeModeSibling) {
                _textUIView.printWrongInsertCommandMessage();
                continue;
            }
            _mindMapModel->tryInsertNewNode(component, instructionEnum);
            _textUIView.printEnterNodeNameMessage();
            string description;
            description = readLineString();
            _mindMapModel->insertNewNode(component, description, instructionEnum);
            continueInput = false;
        } catch (exception exception) {
            _textUIView.printException(exception);
        }
    }
    _textUIView.printMindMap(_mindMapModel->getMindMap());
    return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
}