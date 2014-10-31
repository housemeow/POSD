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
    Component* _component;
    Component* _childComponent;
    string _description;
    MindMapModel* _mindMapModel;
};