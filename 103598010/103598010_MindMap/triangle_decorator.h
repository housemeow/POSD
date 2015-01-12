#pragma once
#include "component_decorator.h"
class TriangleDecorator :
    public ComponentDecorator
{
public:
    TriangleDecorator(Component* component);
    ~TriangleDecorator();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getWidth();
    int getHeight();
    void draw(IGraphics* graphics);
    Component* clone();
    string getTypeName();
};

