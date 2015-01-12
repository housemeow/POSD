#pragma once
#include "component.h"

class ComponentFactory
{
public:
    ComponentFactory();
    ~ComponentFactory();
    Component* createComponent(ComponentType componentType, int id);
    Component* createComponent(ComponentType componentType);
    //Component* copyMindMap(Component* component);
    int getCurrentId();
    void setCurrentId(int currentId);
    static void resetCurrentId();
private:
    static int _currentId;
};