#pragma once
#include "composite.h"

class Root :
    public Composite
{
public:
    Root(int id);
    ~Root();
    void addSibling(Component* component, Component* insertPosition);
    void addParent(Component* component);
    bool isAncientOf(Component* component);
    string getTypeName();
    Component* getMindMap();
};

