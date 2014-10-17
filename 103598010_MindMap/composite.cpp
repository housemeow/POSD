#include "stdafx.h"
#include "composite.h"

Composite::Composite(int id): Component(id)
{
}

Composite::~Composite()
{
}

// 新增一個子節點
void Composite::addChild(Component* component)
{
    if (component) {
        component->setParent(this);
        _children.push_back(component);
    }
}

// 新增一個臨節點
void Composite::addSibling(Component* component)
{
    if (component) {
        _parent->addChild(component);
    }
}

// 新增父節點
void Composite::addParent(Component* component)
{
    if (component) {
        _parent->addChild(component);
        component->addChild(this);
    }
}

bool Composite::isAncientOf(Component* component)
{
    if (this == component) {
        return true;
    } else if(component->getParent() != NULL) {
        return isAncientOf(component->getParent());
    }
    return false;
}