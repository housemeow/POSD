#include "stdafx.h"
#include "triangle_decorator.h"


TriangleDecorator::TriangleDecorator(Component* component) : ComponentDecorator(component)
{
}


TriangleDecorator::~TriangleDecorator()
{
}

int TriangleDecorator::getX()
{
    return _component->getX() - _component->getWidth() / 2;
}

void TriangleDecorator::setX(int x)
{
    Component::setX(x);
    _component->setX(x + _component->getWidth() / 2);
}

int TriangleDecorator::getY()
{
    return _component->getY() - _component->getHeight();
}

void TriangleDecorator::setY(int y)
{
    Component::setY(y);
    _component->setY(y + _component->getHeight());
}

int TriangleDecorator::getWidth()
{
    return _component->getWidth() * 2;
}

int TriangleDecorator::getHeight()
{
    return _component->getHeight() * 2 + ComponentDecorator::PADDING / 2;
}

void TriangleDecorator::draw(IGraphics* graphics)
{
    ComponentDecorator::draw(graphics);
    if (graphics != NULL)
        graphics->drawTriangle(getX(), getY(), getWidth(), getHeight());
}
Component* TriangleDecorator::clone()
{
    return new TriangleDecorator(_component->clone());
}
string TriangleDecorator::getTypeName()
{
    return "triangle";
}
