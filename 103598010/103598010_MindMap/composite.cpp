#include "stdafx.h"
#include "composite.h"
#include "component_factory.h"

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
        component->setParent(this);
        _children.push_back(component);
    }
}

// �s�W�@���{�`�I
void Composite::addSibling(Component* component, Component* insertPosition)
{
    if (component) {
        component->setParent(_parent);
        list<Component*>::iterator iterator;
        for (iterator = _parent->getNodeList().begin(); iterator != _parent->getNodeList().end(); iterator++) {
            if (*iterator == this) {
                break;
            }
        }
        ++iterator;
        _parent->getNodeList().insert(iterator, component);
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

bool Composite::isAncientOf(Component* component)
{
    if (this == component) {
        return true;
    } else if(component->getParent() != NULL) {
        return isAncientOf(component->getParent());
    }
    return false;
}