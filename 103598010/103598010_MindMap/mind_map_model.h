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
    Component* createNode(int id, ComponentType componentType, string description);
    void changeParentCommand(Component* component, Component* parentComponent);
    void insertChildNodeCommand(Component* component, string description);
    Component* insertChildNode(int componentId, string description);
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
    void deleteComponentCommand(Component* component);
    void deleteComponentTree(Component* component);
    Component* insertSiblingNode(Component* component, string description);
    void insertSiblingNodeCommand(Component* component, string description);
    void insertParentNode(Component* component, string description);
    void insertParentNodeCommand(Component* component, string description);
    int getUndoCount();
    int getRedoCount();
private:
    Component* _mindMap;
    CommandManager _commandManager;
};

