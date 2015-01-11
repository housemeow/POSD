#pragma once
#include "component.h"

class ComponentDecorator: public Component
{
public:
    static int GAP;
    ComponentDecorator(Component* component);
    virtual ~ComponentDecorator();
    virtual void draw() = 0;
    virtual string getDecoratorName() = 0;
    string getDescription();
    int getWidth();
    int getHeight();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
protected:
    Component* _component;
};