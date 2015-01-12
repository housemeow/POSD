#include "rectangle_decorator.h"

const string RectangleDecorator::NAME = "Rectangle";

RectangleDecorator::RectangleDecorator(Component* component) : ComponentDecorator(component)
{
}

RectangleDecorator::~RectangleDecorator()
{
}

int RectangleDecorator::getX()
{
    return _component->getX() - ComponentDecorator::PADDING;
}

void RectangleDecorator::setX(int x)
{
    Component::setX(x);
    _component->setX(x + ComponentDecorator::PADDING);
}

int RectangleDecorator::getY()
{
    return _component->getY() - ComponentDecorator::PADDING;
}

void RectangleDecorator::setY(int y)
{
    Component::setY(y);
    _component->setY(y + ComponentDecorator::PADDING);
}

int RectangleDecorator::getWidth()
{
    return _component->getWidth() + ComponentDecorator::PADDING * 2;
}

int RectangleDecorator::getHeight()
{
    return _component->getHeight() + ComponentDecorator::PADDING * 2;
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
    return NAME;
}
