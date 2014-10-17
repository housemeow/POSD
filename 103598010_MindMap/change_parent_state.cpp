#include "stdafx.h"
#include "change_parent_state.h"
#include "menu_state.h"
#include "change_parent_command.h"

ChangeParentState::ChangeParentState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}


ChangeParentState::~ChangeParentState()
{
}

TextUIState* ChangeParentState::run()
{
    int id;
    while (true) {
        id = readInt();
        Component* parentComponent = _mindMapModel->getMindMap()->findNode(id);
        if (parentComponent) {
            if (parentComponent != _component) {
                ChangeParentCommand* changeParentCommand = new ChangeParentCommand(_component, parentComponent);
                _mindMapModel->execute(changeParentCommand);
                return new MenuState(_mindMapModel);
            } else {
                _textUIView.printEnterParent();
            }
        } else {
            _textUIView.printNodeIsNotExist();
        }
    }
    _textUIView.printParentCannotSelectItself();
    cout << "change parent\n";
    return new MenuState(_mindMapModel);
}