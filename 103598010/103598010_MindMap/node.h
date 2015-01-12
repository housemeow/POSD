#pragma once
#include "composite.h"
#include "component_visitor.h"

class ComponentVisitor;

class Node :
    public Composite
{
public:
    Node(int id);
    ~Node();
    string getTypeName();
    Component* getMindMap();
    void accept(ComponentVisitor* componentVisitor);
    Component* clone();
};

