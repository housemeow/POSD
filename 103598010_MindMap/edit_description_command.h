#pragma once
#include "command.h"
class EditDescriptionCommand :
    public Command
{
public:
    EditDescriptionCommand(Component* component, string description);
    EditDescriptionCommand();
    ~EditDescriptionCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    string _previousDescription;
    string _description;
};

