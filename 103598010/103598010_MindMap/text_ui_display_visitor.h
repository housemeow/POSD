#pragma once
#include "component_visitor.h"
class TextUIDisplayVisitor :
    public ComponentVisitor
{
public:
    TextUIDisplayVisitor();
    ~TextUIDisplayVisitor();
    void visit(Node* node);
    void visit(Root* root);
    void visit(Component* component);
    void getMindMapString(Component* component, stringstream& stringStream, bool needVerticleLine);
};

