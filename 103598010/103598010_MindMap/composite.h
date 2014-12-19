#pragma once
#include "component.h"

class Composite :
    public Component
{
public:
    Composite(int id);
    ~Composite();
    void addChild(Component* component);
    void removeChild(Component* component);
    void addSibling(Component* component, Component* insertPosition);
    void addParent(Component* component);
    bool isAncientOf(Component* component);
    Component* clone();
};

