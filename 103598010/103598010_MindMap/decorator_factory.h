#pragma once
#include "rectangle_decorator.h"
#include "ellipse_decorator.h"
#include "triangle_decorator.h"

class DecoratorFactory
{
public:
    DecoratorFactory();
    ~DecoratorFactory();
    ComponentDecorator* create(string decorator, Component* component);
};

