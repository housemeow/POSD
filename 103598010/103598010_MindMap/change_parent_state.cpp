#include "stdafx.h"
#include "change_parent_state.h"
#include "menu_state.h"

ChangeParentState::ChangeParentState(MindMapModel* mindMapModel, Component* component) : TextUIState(mindMapModel)
{
    _component = component;
}


ChangeParentState::~ChangeParentState()
{
}

TextUIState* ChangeParentState::run()
{
    if (_component == _mindMapModel->getMindMap()) {
        _textUIView->printRootCannotChangeParent();
        return new MenuState(_mindMapModel);
    }
    _textUIView->printEnterParentID();
    int id = readInt(false);
    if (_component->getId() == id) {
        _textUIView->printParentCannotSelectItself();
        return new ChangeParentState(_mindMapModel, _component);
    }
    Component* parentComponent = _mindMapModel->getMindMap()->findNode(id);
    if (!parentComponent) {
        _textUIView->printNodeIsNotExist();
        return new ChangeParentState(_mindMapModel, _component);
    }
    _mindMapModel->changeParentCommand(_component, parentComponent);
    _textUIView->printMindMap(_mindMapModel->getMindMap());
    return new MenuState(_mindMapModel);
}