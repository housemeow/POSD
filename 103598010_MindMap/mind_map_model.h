#pragma once
#include "component.h"
#include "command_manager.h"
#include "command.h"
#include "enumeration.h"

class MindMapModel
{
public:
    MindMapModel();
    ~MindMapModel();
    void createMindMap(string mindMapName);
    Component* insertNewNode(Component* node, string description, InsertNodeMode insertMode);
    Component* insertNode(Component* component, Component* node, InsertNodeMode insertMode);
    Component* createNode(ComponentType componentType, string description);
    void insertChildNode(Component* component, string description);
    void tryInsertNewNode(Component* component, InsertNodeMode insertMode);
    void saveMindMap(string fileName);
    void loadMindMap(string filePath);
    void undo();
    void redo();
    void execute(Command* command);
    Component* findComponent(list<Component*> components, int id);
    ComponentType getComponentType(int id);
    void readComponentData(string line, int& id, string& description, string& children);
    Component* getMindMap();
    void editDescription(Component* component, string description);
    void deleteComponent(Component* component);
    void insertSiblingNode(Component* component, string description);
    void insertParentNode(Component* component, string description);
private:
    Component* _mindMap;
    int _currentId;
    CommandManager _commandManager;
};

