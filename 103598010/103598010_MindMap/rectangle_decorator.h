#pragma once
#include "component_decorator.h"

class RectangleDecorator :
    public ComponentDecorator
{
public:
    RectangleDecorator(Component* component);
    ~RectangleDecorator();
    string getDecoratorName();
    int getWidth();
    int getHeight();
    void draw(IGraphics* graphics);
    Component* clone();
    string getTypeName();
};

