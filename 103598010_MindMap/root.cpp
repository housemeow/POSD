#include "stdafx.h"
#include "root.h"

Root::Root(int id) : Composite(id)
{
}

Root::~Root()
{
}

// Root無法新增臨節點
void Root::addSibling(Component* component)
{
    throw exception("Root can't insert sibling node");
}

// Root無法新增父節點
void Root::addParent(Component* component)
{
    throw exception("Root can't insert parent node");
}

// 取得Root的名稱
string Root::getTypeName()
{
    return "Root";
}

bool Root::isAncientOf(Component* component)
{
    return true;
}