#pragma once
#include "component_decorator.h"
class EllipseDecorator :
    public ComponentDecorator
{
public:
    EllipseDecorator(Component* component);
    ~EllipseDecorator();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getWidth();
    int getHeight();
    int getA();
    void draw(IGraphics* graphics);
    Component* clone();
    string getTypeName();
};

