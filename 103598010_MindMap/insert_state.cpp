#include "stdafx.h"
#include "insert_state.h"
#include "menu_state.h"
#include "componentFactory.h"

InsertState::InsertState(MindMapModel* mindMapModel) : TextUIState(mindMapModel)
{
}


InsertState::~InsertState()
{
}

TextUIState* InsertState::run()
{
    if (!_mindMapModel->getMindMap()) {
        _textUIView.printMindMapNotExist();
        return new MenuState(_mindMapModel);
    }
    _textUIView.printMindMap(_mindMapModel);
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
        } catch (string exception) {
            _textUIView.printLine(exception);
        }
    }
    _textUIView.printMindMap(_mindMapModel);
    return new MenuState(_mindMapModel);
}