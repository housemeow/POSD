#include "stdafx.h"
#include "edit_description_command.h"
#include "component.h"
#include "mind_map_model.h"

EditDescriptionCommand::EditDescriptionCommand(MindMapModel* mindMapModel, Component* component, string description)
{
    _mindMapModel = mindMapModel;
    _component = component;
    _previousDescription = component->getDescription();
    _description = description;
}

EditDescriptionCommand::EditDescriptionCommand()
{
}


EditDescriptionCommand::~EditDescriptionCommand()
{
}

void EditDescriptionCommand::execute()
{
    _mindMapModel->editDescription(_component, _description);
}

void EditDescriptionCommand::unexecute()
{
    _component->setDescription(_previousDescription);
}