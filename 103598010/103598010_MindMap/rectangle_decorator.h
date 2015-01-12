#pragma once
#include "component_decorator.h"

class RectangleDecorator :
    public ComponentDecorator
{
public:
    RectangleDecorator(Component* component);
    ~RectangleDecorator();
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
