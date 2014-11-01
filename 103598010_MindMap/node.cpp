#include "stdafx.h"
#include "node.h"

Node::Node(int id) : Composite(id)
{
}

Node::~Node()
{
}

// ���oNode���W��
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