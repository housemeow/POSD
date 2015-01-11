#include "stdafx.h"
#include "component_decorator.h"


int ComponentDecorator::GAP = 10;

ComponentDecorator::ComponentDecorator(Component* component)
{
    _component = component;
}

ComponentDecorator::~ComponentDecorator()
{
}

string ComponentDecorator::getDescription()
{
    return getDecoratorName() + _component->getDescription();
}

int ComponentDecorator::getWidth()
{
    return _component->getWidth() + ComponentDecorator::GAP * 2;
}

int ComponentDecorator::getHeight()
{
    return _component->getHeight() + ComponentDecorator::GAP * 2;
}

int ComponentDecorator::getX()
{
    return _component->getX() - ComponentDecorator::GAP;
}

void ComponentDecorator::setX(int x)
{
    _component->setX(x + ComponentDecorator::GAP);
}

int ComponentDecorator::getY()
{
    return _component->getY() - ComponentDecorator::GAP;
}

void ComponentDecorator::setY(int y)
{
    _component->setY(y + ComponentDecorator::GAP);
}