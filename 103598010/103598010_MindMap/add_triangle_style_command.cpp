#include "stdafx.h"
#include "add_triangle_style_command.h"

AddTriangleStyleCommand::AddTriangleStyleCommand(Component* component)
{
    _component = component;
}


AddTriangleStyleCommand::~AddTriangleStyleCommand()
{
    if (_triangleDecorator != NULL) {
        delete _triangleDecorator;
    }
}

void AddTriangleStyleCommand::execute()
{
    _triangleDecorator = new TriangleDecorator(_component);
    _component->getParent()->replace(_component, _triangleDecorator);
}

void AddTriangleStyleCommand::unexecute()
{
    _triangleDecorator->getParent()->replace(_triangleDecorator, _component);
    delete _triangleDecorator;
    _triangleDecorator = NULL;
}