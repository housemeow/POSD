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
        _textUIView->printMindMapNotExist();
        return TextUIStateFactory::createTextUIState(MenuStateInstruction, _mindMapModel);
    }
    _textUIView->printMindMap(_mindMapModel->getMindMap());
    int id;
    Component* component = NULL;
    while (component == NULL) {
        _textUIView->printEnterNodeIDMessage();
        id = readInt();
        component = _mindMapModel->getMindMap()->findNode(id);
    }
    ComponentFactory factory;
    while (true) {
        _textUIView->printInsertNewNodeMenu();
        char instruction;
        *cin >> instruction;
        InsertNodeMode instructionEnum = (InsertNodeMode)instruction;
        if (instructionEnum != InsertNodeModeParent &&
                instructionEnum != InsertNodeModeChild &&
                instructionEnum != InsertNodeModeSibling) {
            _textUIView->printWrongInsertCommandMessage();
            continue;
        }
        try {
            _mindMapModel->tryInsertNewNode(component, instructionEnum);
        } catch (exception exception) {
            _textUIView->printException(exception);
            continue;
        }
        _textUIView->printEnterNodeNameMessage();
        switch (instructionEnum) {
            case InsertNodeModeParent:
                return TextUIStateFactory::createTextUIState(InsertParentNodeStateInstruction, _mindMapModel, component);
            case InsertNodeModeChild:
                return TextUIStateFactory::createTextUIState(InsertChildNodeStateInstruction, _mindMapModel, component);
            case InsertNodeModeSibling:
                return TextUIStateFactory::createTextUIState(InsertSiblingNodeStateInstruction, _mindMapModel, component);
        }
    }
}