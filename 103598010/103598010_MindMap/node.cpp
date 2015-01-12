#include "stdafx.h"
#include "node.h"

Node::Node(int id) : Composite(id)
{
}

Node::~Node()
{
}

// 取得Node的名稱
string Node::getTypeName()
{
    return "Node";
}

Component* Node::getMindMap()
{
    if (_parent == NULL)
        return NULL;
    return _parent->getMindMap();
}

// visitor pattern 訪問
void Node::accept(ComponentVisitor* componentVisitor)
{
    componentVisitor->visit(this);
}

Component* Node::clone()
{
    Node* newNode = new Node(getId());
    newNode->setDescription(getDescription());
    for (list<Component*>::iterator iterator = getNodeList().begin(); iterator != getNodeList().end(); iterator++)
        newNode->getNodeList().push_back((*iterator)->clone());
    return newNode;
}