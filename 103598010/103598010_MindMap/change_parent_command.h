#pragma once
#include "command.h"

class ChangeParentCommand :
    public Command
{
public:
    ChangeParentCommand(Component* component, Component* parentComponent);
    ~ChangeParentCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    int _parentComponentId;
    int _originParentComponentId;
    Component* _mindMap;
    int _originPosition;
    list<int> _childrenId;
};

