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
        if (component->getParent()) {
            component->getParent()->getNodeList().remove(component);
        }
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