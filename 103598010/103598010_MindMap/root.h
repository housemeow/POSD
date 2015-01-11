#pragma once
#include "composite.h"
#include "component_visitor.h"

class ComponentVisitor;

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
    void accept(ComponentVisitor* componentVisitor);
};

