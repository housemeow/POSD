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
    throw kRootCannotAddSiblingException;
}

// Root無法新增父節點
void Root::addParent(Component* component)
{
    throw kRootCannotAddParentException;
}

// 取得Root的名稱
string Root::getTypeName()
{
    return kRootName;
}