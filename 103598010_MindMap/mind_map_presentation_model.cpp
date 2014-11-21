#include "stdafx.h"
#include "mind_map_model.h"
#include "mind_map_presentation_model.h"
#include "component.h"
#include <string>

using namespace std;

MindMapPresentatinoModel::MindMapPresentatinoModel(MindMapModel* mindMapModel)
{
    _mindMapModel = mindMapModel;
}

MindMapPresentatinoModel::~MindMapPresentatinoModel()
{
}

Component* MindMapPresentatinoModel::getMindMap()
{
    return _mindMapModel->getMindMap();
}

void MindMapPresentatinoModel::createMindMap(string mindMapName)
{
    _mindMapModel->createMindMap(mindMapName);
}

void MindMapPresentatinoModel::insertNewNode(Component* node, string description, InsertNodeMode insertMode)
{
    _mindMapModel->insertNewNode(node, description, insertMode);
}

void MindMapPresentatinoModel::loadMindMap(string filePath)
{
    _mindMapModel->loadMindMap(filePath);
}