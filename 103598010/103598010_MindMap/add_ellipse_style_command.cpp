#include "stdafx.h"
#include "add_ellipse_style_command.h"

AddEllipseStyleCommand::AddEllipseStyleCommand(Component* component)
{
    _component = component;
}


AddEllipseStyleCommand::~AddEllipseStyleCommand()
{
    if (_ellipseDecorator != NULL) {
        delete _ellipseDecorator;
    }
}

void AddEllipseStyleCommand::execute()
{
    _ellipseDecorator = new EllipseDecorator(_component);
    _component->getParent()->replace(_component, _ellipseDecorator);
}

void AddEllipseStyleCommand::unexecute()
{
    _ellipseDecorator->getParent()->replace(_ellipseDecorator, _component);
}