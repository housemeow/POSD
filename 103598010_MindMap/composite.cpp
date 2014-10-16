#include "stdafx.h"
#include "composite.h"

Composite::Composite(int id): Component(id)
{
}

Composite::~Composite()
{
}

// �s�W�@�Ӥl�`�I
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

// �s�W�@���{�`�I
void Composite::addSibling(Component* component)
{
    if (component) {
        _parent->addChild(component);
    }
}

// �s�W���`�I
void Composite::addParent(Component* component)
{
    if (component) {
        _parent->addChild(component);
        component->addChild(this);
    }
}