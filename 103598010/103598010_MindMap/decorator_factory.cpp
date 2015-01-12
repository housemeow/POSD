#include "stdafx.h"
#include "decorator_factory.h"


DecoratorFactory::DecoratorFactory()
{
}


DecoratorFactory::~DecoratorFactory()
{
}


ComponentDecorator* DecoratorFactory::create(string decorator, Component* component)
{
    if (decorator == RectangleDecorator::NAME) {
        return new RectangleDecorator(component);
    } else if (decorator == EllipseDecorator::NAME) {
        return new EllipseDecorator(component);
    } else if (decorator == TriangleDecorator::NAME) {
        return new TriangleDecorator(component);
    } else {
        throw exception("no support decorator.");
    }
}