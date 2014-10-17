#include "stdafx.h"
#include "command_manager.h"
#include "command.h"


CommandManager::CommandManager()
{
}

CommandManager::~CommandManager()
{
    while (!undoStack.empty()) {
        delete undoStack.top();
        undoStack.pop();
    }
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
}

void CommandManager::execute(Command* command)
{
    command->execute();
    undoStack.push(command);
}

void CommandManager::undo()
{
    if (undoStack.empty()) {
        throw exception("Cant't Undo!");
    } else {
        Command* command = undoStack.top();
        undoStack.pop();
        command->unexecute();
        redoStack.push(command);
    }
}

void CommandManager::redo()
{
    if (redoStack.empty()) {
        throw exception("Cant't Redo!");
    } else {
        Command* command = redoStack.top();
        redoStack.pop();
        command->execute();
        undoStack.push(command);
    }
}