#pragma once
#include "command.h"
class InsertSiblingNodeCommand :
    public Command
{
public:
    InsertSiblingNodeCommand(MindMapModel* mindMapModel, Component* component, string description);
    InsertSiblingNodeCommand();
    ~InsertSiblingNodeCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    Component* _siblingComponent;
    string _description;
    MindMapModel* _mindMapModel;
};