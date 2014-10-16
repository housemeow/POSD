#include "stdafx.h"
#include "component_factory.h"
#include "component.h"
#include "root.h"
#include "node.h"

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