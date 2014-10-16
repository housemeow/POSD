#pragma once
#include "component.h"

class ComponentFactory
{
public:
    ComponentFactory();
    ~ComponentFactory();
    Component* createComponent(ComponentType componentType, int id);
};