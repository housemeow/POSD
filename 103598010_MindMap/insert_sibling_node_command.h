#pragma once
#include "command.h"
class InsertSiblingNodeCommand :
    public Command
{
public:
    InsertSiblingNodeCommand();
    ~InsertSiblingNodeCommand();
    void execute();
    void unexecute();
};

