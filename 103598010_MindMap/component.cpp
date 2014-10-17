#include "stdafx.h"
#include "component.h"

using namespace std;

Component::Component(int id)
{
    _id = id;
    _parent = NULL;
}

Component::~Component()
{
}

int Component::getId()
{
    return _id;
}

void Component::setId(int id)
{
    _id = id;
}

string Component::getDescription()
{
    return _description;
}

void Component::setDescription(string description)
{
    _description = description;
}

list<Component*>& Component::getNodeList()
{
    return _children;
}

Component* Component::getParent()
{
    return _parent;
}

string Component::getName()
{
    ostringstream stream;
    stream << _description << "(" << getTypeName() << ", ID: " << _id << ")";
    return stream.str();
}

void Component::setParent(Component* parent)
{
    if (this->getParent()) {
        this->getParent()->getNodeList().remove(this);
    }
    _parent = parent;
}

// 尋找指定id的節點
Component* Component::findNode(int id)
{
    if (_id == id) {
        return this;
    } else {
        for (ComponentIterator iterator = _children.begin(), end = _children.end(); iterator != end; ++iterator) {
            Component* result = (*iterator)->findNode(id);
            if (result) {
                return result;
            }
        }
    }
    return NULL;
}