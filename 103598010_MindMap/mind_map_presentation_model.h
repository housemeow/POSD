#pragma once
#include "mind_map_model.h"
#include <string>

using namespace std;

class MindMapPresentatinoModel
{
public:
    MindMapPresentatinoModel(MindMapModel* mindMapModel);
    ~MindMapPresentatinoModel();
    Component* getMindMap();
    void createMindMap(string);
    void insertNewNode(Component*, string, InsertNodeMode);
    void loadMindMap(string filePath);
private:
    MindMapModel* _mindMapModel;
};

