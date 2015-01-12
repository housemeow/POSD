#pragma once
#include "command.h"
#include "rectangle_decorator.h"

class AddRectangleStyleCommand :
    public Command
{
public:
    AddRectangleStyleCommand(Component* component);
    ~AddRectangleStyleCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    RectangleDecorator* _rectangleDecorator;
};

