#include "stdafx.h"
#include "triangle_decorator.h"


const string TriangleDecorator::NAME = "Triangle";

TriangleDecorator::TriangleDecorator(Component* component) : ComponentDecorator(component)
{
}


TriangleDecorator::~TriangleDecorator()
{
}

int TriangleDecorator::getX()
{
    return _component->getX() - ComponentDecorator::PADDING * 2;
}

void TriangleDecorator::setX(int x)
{
    Component::setX(x);
    _component->setX(x + ComponentDecorator::PADDING * 2);
}

int TriangleDecorator::getY()
{
    return _component->getY() - ComponentDecorator::PADDING;
}

void TriangleDecorator::setY(int y)
{
    Component::setY(y);
    _component->setY(y + ComponentDecorator::PADDING);
}

int TriangleDecorator::getWidth()
{
    return _component->getWidth() + ComponentDecorator::PADDING * 4;
}

int TriangleDecorator::getHeight()
{
    return _component->getHeight()  + ComponentDecorator::PADDING * 2 ;
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
    return NAME;
}
