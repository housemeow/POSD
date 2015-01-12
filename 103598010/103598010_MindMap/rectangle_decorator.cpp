#include "rectangle_decorator.h"

RectangleDecorator::RectangleDecorator(Component* component) : ComponentDecorator(component)
{
}


RectangleDecorator::~RectangleDecorator()
{
}

int RectangleDecorator::getWidth()
{
    return _component->getWidth() + ComponentDecorator::GAP * 2;
}

int RectangleDecorator::getHeight()
{
    return _component->getHeight() + ComponentDecorator::GAP * 2;
}

string RectangleDecorator::getDecoratorName()
{
    return "rectangle";
}

void RectangleDecorator::draw(IGraphics* graphics)
{
    ComponentDecorator::draw(graphics);
    if (graphics != NULL)
        graphics->drawRectangle(getX(), getY(), getWidth(), getHeight());
}
Component* RectangleDecorator::clone()
{
    return new RectangleDecorator(_component->clone());
}
string RectangleDecorator::getTypeName()
{
    return "rectangle";
}
