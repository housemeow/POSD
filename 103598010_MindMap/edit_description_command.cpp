#include "stdafx.h"
#include "edit_description_command.h"
#include "component.h"

EditDescriptionCommand::EditDescriptionCommand(Component* component, string description)
{
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
    _component->setDescription(_description);
}

void EditDescriptionCommand::unexecute()
{
    _component->setDescription(_previousDescription);
}