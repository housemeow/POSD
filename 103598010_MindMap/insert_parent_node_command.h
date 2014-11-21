#pragma once
#include "command.h"
class InsertParentNodeCommand :
    public Command
{
public:
    InsertParentNodeCommand(MindMapModel* mindMapModel, Component* component, string description);
    InsertParentNodeCommand();
    ~InsertParentNodeCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    string _description;
    MindMapModel* _mindMapModel;
};