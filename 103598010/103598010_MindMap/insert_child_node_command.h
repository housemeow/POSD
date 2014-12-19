#pragma once
#include "command.h"
class InsertChildNodeCommand :
    public Command
{
public:
    InsertChildNodeCommand(MindMapModel* mindMapModel, Component* component, string description);
    InsertChildNodeCommand();
    ~InsertChildNodeCommand();
    void execute();
    void unexecute();
private:
    int _componentId;
    int _childComponentId;
    string _description;
    MindMapModel* _mindMapModel;
};