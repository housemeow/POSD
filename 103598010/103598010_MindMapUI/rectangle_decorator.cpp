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

void RectangleDecorator::draw(IGraphics* graphics)
{
    if (graphics != NULL)
        graphics->drawRectangle(getX(), getY(), getWidth(), getHeight());
}