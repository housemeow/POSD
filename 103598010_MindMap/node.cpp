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