#pragma once
#include "composite.h"

class Root :
    public Composite
{
public:
    Root(int id);
    ~Root();
    void addSibling(Component* component);
    void addParent(Component* component);
    string getTypeName();
};
