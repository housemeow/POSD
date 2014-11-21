#pragma once
#include "command.h"
#include "mind_map_model.h"

class DeleteCommand :
    public Command
{
public:
    DeleteCommand(MindMapModel* mindMapModel, Component* component);
    ~DeleteCommand();
    void execute();
    void unexecute();
private:
    MindMapModel* _mindMapModel;
    Component* _component;
    Component* _parentComponent;
    Component* _mindMap;
    list<int> _childrenId;
    int _id;
    string _description;
    int _originPosition;
};

