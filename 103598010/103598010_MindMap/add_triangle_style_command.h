#pragma once
#include "command.h"
#include "triangle_decorator.h"
class AddTriangleStyleCommand :
    public Command
{
public:
    AddTriangleStyleCommand(Component* component);
    ~AddTriangleStyleCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    TriangleDecorator* _triangleDecorator;
};

