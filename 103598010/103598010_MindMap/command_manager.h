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
    int getUndoCount();
    int getRedoCount();
    void clear();
    void clearRedo();
private:
    stack<Command*> _undoStack;
    stack<Command*> _redoStack;
};

