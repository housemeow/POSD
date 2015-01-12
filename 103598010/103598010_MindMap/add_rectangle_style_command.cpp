#include "stdafx.h"
#include "add_rectangle_style_command.h"
#include "rectangle_decorator.h"

AddRectangleStyleCommand::AddRectangleStyleCommand(Component* component)
{
    _component = component;
}


AddRectangleStyleCommand::~AddRectangleStyleCommand()
{
    if (_rectangleDecorator != NULL) {
        delete _rectangleDecorator;
    }
}

void AddRectangleStyleCommand::execute()
{
    _rectangleDecorator = new RectangleDecorator(_component);
    _component->getParent()->replace(_component, _rectangleDecorator);
}

void AddRectangleStyleCommand::unexecute()
{
    _rectangleDecorator->getParent()->replace(_rectangleDecorator, _component);
    delete _rectangleDecorator;
    _rectangleDecorator = NULL;
}
