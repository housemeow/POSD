#include "rectangle_decorator.h"

RectangleDecorator::RectangleDecorator(Component* component) : ComponentDecorator(component)
{
}


RectangleDecorator::~RectangleDecorator()
{
}

string RectangleDecorator::getDecoratorName()
{
    return "rectangle";
}