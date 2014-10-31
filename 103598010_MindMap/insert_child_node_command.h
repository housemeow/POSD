#pragma once
#include "command.h"
class InsertChildNodeCommand :
    public Command
{
public:
    InsertChildNodeCommand();
    ~InsertChildNodeCommand();
    void execute();
    void unexecute();
};

