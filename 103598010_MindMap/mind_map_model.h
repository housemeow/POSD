#pragma once
#include "component.h"

class MindMapModel
{
public:
    MindMapModel();
    ~MindMapModel();
    void createMindMap(string mindMapName);
    void insertNewNode(Component* node, string description, InsertNodeMode insertMode);
    void insertNode(Component* component, Component* node, InsertNodeMode insertMode);
    void tryInsertNewNode(Component* component, InsertNodeMode insertMode);
    void saveMindMap();
    Component* getMindMap();
private:
    Component* _mindMap;
    int _currentId;

};

