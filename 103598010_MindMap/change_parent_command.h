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
    Component* _parentComponent;
    Component* _originParentComponent;
    list<Component*> _children;
};

