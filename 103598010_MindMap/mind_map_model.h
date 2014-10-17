#pragma once
#include "component.h"
#include "command_manager.h"
#include "command.h"

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
    void loadMindMap(string filePath);
    void undo();
    void redo();
    void execute(Command* command);
    Component* findComponent(list<Component*> components, int id);
    ComponentType getComponentType(int id);
    void readComponentData(string line, int& id, string& description, string& children);
    Component* getMindMap();
private:
    Component* _mindMap;
    int _currentId;
    CommandManager _commandManager;
};

