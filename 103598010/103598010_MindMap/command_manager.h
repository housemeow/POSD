#pragma once
#include <stack>
#include "command.h"

class CommandManager
{
public:
    CommandManager();
    ~CommandManager();
    void execute(Command* command);
    void undo();
    void redo();
private:
    stack<Command*> undoStack;
    stack<Command*> redoStack;
};

