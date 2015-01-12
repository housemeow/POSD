#pragma once

class Component;
class Node;
class Root;

class ComponentVisitor
{
public:
    ComponentVisitor();
    virtual ~ComponentVisitor();
    virtual void visit(Node* node);
    virtual void visit(Root* root);
    virtual void visit(Component* component);
};

