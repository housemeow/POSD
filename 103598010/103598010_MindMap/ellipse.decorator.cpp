#include "stdafx.h"
#include "ellipse_decorator.h"


const string EllipseDecorator::NAME = "Ellipse";

EllipseDecorator::EllipseDecorator(Component* component) : ComponentDecorator(component)
{
}


EllipseDecorator::~EllipseDecorator()
{
}

int EllipseDecorator::getX()
{
    return Component::getX();
    double A = getA();
    return _component->getX() - ComponentDecorator::PADDING;// (A - _component->getWidth() / 2);
}

void EllipseDecorator::setX(int x)
{
    Component::setX(x);
    double A = getA();
    _component->setX(x + ComponentDecorator::PADDING);//(A - _component->getWidth() / 2));
}

int EllipseDecorator::getY()
{
    return Component::getY();
    return _component->getY() - ComponentDecorator::PADDING;
}

void EllipseDecorator::setY(int y)
{
    Component::setY(y);
    _component->setY(y + ComponentDecorator::PADDING);
}

int EllipseDecorator::getWidth()
{
    return _component->getWidth() + ComponentDecorator::PADDING * 2;// getA() * 2;
}

int EllipseDecorator::getA()
{
    double x = _component->getWidth() / 2;
    double y = _component->getHeight() / 2;
    double B = _component->getHeight() / 2 + ComponentDecorator::PADDING;
    double A = x * sqrt(1 / (1 - y * y / (B * B)));
    return (int)A;
}

int EllipseDecorator::getHeight()
{
    return _component->getHeight() + ComponentDecorator::PADDING * 2;
}

void EllipseDecorator::draw(IGraphics* graphics)
{
    ComponentDecorator::draw(graphics);
    if (graphics != NULL)
        graphics->drawEllipse(getX(), getY(), getWidth(), getHeight());
}
Component* EllipseDecorator::clone()
{
    return new EllipseDecorator(_component->clone());
}
string EllipseDecorator::getTypeName()
{
    return NAME;
}
