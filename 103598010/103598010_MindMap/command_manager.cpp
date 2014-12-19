#include "stdafx.h"
#include "command_manager.h"
#include "command.h"


CommandManager::CommandManager()
{
}

CommandManager::~CommandManager()
{
    while (!_undoStack.empty()) {
        delete _undoStack.top();
        _undoStack.pop();
    }
    while (!_redoStack.empty()) {
        delete _redoStack.top();
        _redoStack.pop();
    }
}

void CommandManager::execute(Command* command)
{
    command->execute();
    _undoStack.push(command);
}

void CommandManager::undo()
{
    if (_undoStack.empty()) {
        throw exception("Cant't Undo!");
    } else {
        Command* command = _undoStack.top();
        _undoStack.pop();
        command->unexecute();
        _redoStack.push(command);
    }
}

void CommandManager::redo()
{
    if (_redoStack.empty()) {
        throw exception("Cant't Redo!");
    } else {
        Command* command = _redoStack.top();
        _redoStack.pop();
        command->execute();
        _undoStack.push(command);
    }
}

void CommandManager::clear()
{
    while (!_undoStack.empty())
        _undoStack.pop();
    clearRedo();
}

void CommandManager::clearRedo()
{
    while (!_redoStack.empty())
        _redoStack.pop();
}

int CommandManager::getUndoCount()
{
    return _undoStack.size();
}

int CommandManager::getRedoCount()
{
    return _redoStack.size();
}