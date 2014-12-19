#pragma once
#include "command.h"
#include "mind_map_model.h"

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
    MindMapModel* _mindMapModel;
    Component* _component;
    string _previousDescription;
    string _description;
};

