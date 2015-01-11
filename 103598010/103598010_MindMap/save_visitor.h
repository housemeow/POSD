#pragma once
#include "component_visitor.h"
#include "mind_map_model.h"
#include "component_factory.h"

class SaveVisitor :
    public ComponentVisitor
{
public:
    SaveVisitor(string fileName);
    ~SaveVisitor();
    void visit(Node* node);
    void visit(Root* root);
    void visit(Component* component);
private:
    string _fileName;
};

