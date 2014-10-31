#pragma once
#include "command.h"
class InsertParentNodeCommand :
    public Command
{
public:
    InsertParentNodeCommand();
    ~InsertParentNodeCommand();
    void execute();
    void unexecute();
};

