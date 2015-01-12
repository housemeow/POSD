#include "stdafx.h"
#include "component_visitor.h"

ComponentVisitor::ComponentVisitor()
{
}

ComponentVisitor::~ComponentVisitor()
{
}

void ComponentVisitor::visit(Node* node) {}
void ComponentVisitor::visit(Root* root) {}
void ComponentVisitor::visit(Component* component) {}