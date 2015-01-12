#include "stdafx.h"
#include "component_decorator.h"


//int ComponentDecorator::GAP = 5;

ComponentDecorator::ComponentDecorator(Component* component) : Component(component->getId())
{
    _component = component;
}

ComponentDecorator::~ComponentDecorator()
{
}

void ComponentDecorator::draw(IGraphics* graphics)
{
    _component->draw(graphics);
}

Component* ComponentDecorator::getComponent()
{
    return _component;
}

string ComponentDecorator::getDescription()
{
    return _component->getDescription();
}

Component* ComponentDecorator::getMindMap()
{
    return _component->getMindMap();
}
void ComponentDecorator::addChild(Component* component)
{
    _component->addChild(component);
}
void ComponentDecorator::addSibling(Component* component, Component* insertPosition)
{
    _component->addSibling(component, insertPosition);
}
void ComponentDecorator::addParent(Component* component)
{
    _component->addParent(component);
}
bool ComponentDecorator::isAncientOf(Component* component)
{
    return _component->isAncientOf(component);
}
void ComponentDecorator::accept(ComponentVisitor* componentVisitor)
{
    //_component->accept(componentVisitor);
    componentVisitor->visit(this);
}

void ComponentDecorator::setDescription(string description)
{
    _component->setDescription(description);
}

string ComponentDecorator::getName()
{
    return _component->getName();
}

Component* ComponentDecorator::getParent()
{
    return _component->getParent();
}

void ComponentDecorator::setParent(Component* parent)
{
    _component->setParent(parent);
}

Component* ComponentDecorator::findNode(int id)
{
    return _component->findNode(id);
}

list<Component*>& ComponentDecorator::getNodeList()
{
    return _component->getNodeList();
}