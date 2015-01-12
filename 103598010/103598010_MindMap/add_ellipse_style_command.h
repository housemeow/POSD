#pragma once
#include "command.h"
#include "ellipse_decorator.h"
class AddEllipseStyleCommand :
    public Command
{
public:
    AddEllipseStyleCommand(Component* component);
    ~AddEllipseStyleCommand();
    void execute();
    void unexecute();
private:
    Component* _component;
    EllipseDecorator* _ellipseDecorator;
};

