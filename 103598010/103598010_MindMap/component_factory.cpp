#include "stdafx.h"
#include "component_factory.h"
#include "component.h"
#include "root.h"
#include "node.h"

int ComponentFactory::_currentId = 0;

ComponentFactory::ComponentFactory()
{
}

ComponentFactory::~ComponentFactory()
{
}

// 依據ComponentType創造一個Component
Component* ComponentFactory::createComponent(ComponentType componentType, int id)
{
    Component* component = NULL;
    switch (componentType) {
        case ComponentType::ComponentTypeRoot:
            component = new Root(id);
            break;
        case ComponentType::ComponentTypeNode:
            component = new Node(id);
            break;
    }
    return component;
}

Component* ComponentFactory::createComponent(ComponentType componentType)
{
    return createComponent(componentType, _currentId++);
}

Component* ComponentFactory::copyMindMap(Component* component)
{
    if (component != NULL) {
        // create component
        Component* newComponent = new Node(component->getId());
        newComponent->setDescription(component->getDescription());
        list<Component*> componentList = component->getNodeList();
        for (list<Component*>::const_iterator child = componentList.begin(); child != componentList.end(); child++) {
            newComponent->addChild(copyMindMap(*child));
        }
        return newComponent;
    }
    return NULL;
}

int ComponentFactory::getCurrentId()
{
    return _currentId;
}

void ComponentFactory::setCurrentId(int currentId)
{
    _currentId = currentId;
}

void ComponentFactory::resetCurrentId()
{
    _currentId = 0;
}