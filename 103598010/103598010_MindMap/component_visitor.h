#pragma once

class Component;
class Node;
class Root;

class ComponentVisitor
{
public:
    ComponentVisitor();
    virtual ~ComponentVisitor();
    virtual void visit(Node* node) = 0;
    virtual void visit(Root* root) = 0;
};

