#include "rectangle_decorator.h"

RectangleDecorator::RectangleDecorator(Component* component) : ComponentDecorator(component)
{
}

RectangleDecorator::~RectangleDecorator()
{
}

int RectangleDecorator::getX()
{
    return _component->getX() - ComponentDecorator::GAP;
}

void RectangleDecorator::setX(int x)
{
    Component::setX(x);
    _component->setX(x + ComponentDecorator::GAP);
}

int RectangleDecorator::getY()
{
    return _component->getY() - ComponentDecorator::GAP;
}

void RectangleDecorator::setY(int y)
{
    Component::setY(y);
    _component->setY(y + ComponentDecorator::GAP);
}

int RectangleDecorator::getWidth()
{
    return _component->getWidth() + ComponentDecorator::GAP * 2;
}

int RectangleDecorator::getHeight()
{
    return _component->getHeight() + ComponentDecorator::GAP * 2;
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
