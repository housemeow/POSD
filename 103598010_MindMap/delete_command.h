#pragma once
#include "command.h"
class DeleteCommand :
    public Command
{
public:
    DeleteCommand(Component* component);
    ~DeleteCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    Component* _parentComponent;
    list<Component*> _children;
    int _id;
    string _description;
};

