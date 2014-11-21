#include "stdafx.h"
#include "mind_map_model.h"
#include "mind_map_presentation_model.h"
#include "component.h"
#include <string>

using namespace std;

MindMapPresentationModel::MindMapPresentationModel(MindMapModel* mindMapModel)
{
    _mindMapModel = mindMapModel;
    setActionsEnabled(false);
    _selectedComponent = NULL;
}

MindMapPresentationModel::~MindMapPresentationModel()
{
}

Component* MindMapPresentationModel::getMindMap()
{
    return _mindMapModel->getMindMap();
}

void MindMapPresentationModel::createMindMap(string mindMapName)
{
    _mindMapModel->createMindMap(mindMapName);
    setActionsEnabled(false);
}

void MindMapPresentationModel::insertNewNode(Component* node, string description, InsertNodeMode insertMode)
{
    _mindMapModel->insertNewNode(node, description, insertMode);
}

void MindMapPresentationModel::loadMindMap(string filePath)
{
    _mindMapModel->loadMindMap(filePath);
    setActionsEnabled(false);
    _listener->updateUI();
}

bool MindMapPresentationModel::getLoadMindMapActionEnabled()
{
    return _loadMindMapActionEnabled;
}

bool MindMapPresentationModel::getEditNodeActionEnabled()
{
    return _editNodeActionEnabled;
}

bool MindMapPresentationModel::getDeleteNodeActionEnabled()
{
    return _deleteNodeActionEnabled;
}

bool MindMapPresentationModel::getInsertChildActionEnabled()
{
    return _insertChildActionEnabled;
}

bool MindMapPresentationModel::getInsertSiblingActionEnabled()
{
    return _insertSiblingActionEnabled;
}

bool MindMapPresentationModel::getInsertParentActionEnabled()
{
    return _insertParentActionEnabled;
}


bool MindMapPresentationModel::getSelected(Component* component)
{
    map<Component*, bool>::iterator find = _componentSelections.find(component);
    if (find != _componentSelections.end()) {
        return _componentSelections[component];
    } else {
        _componentSelections.insert(pair<Component*, bool>(component, false));
        return false;
    }
}

void MindMapPresentationModel::clickNode(Component* component)
{
    _selectedComponent = component;
    _componentSelections.insert(pair<Component*, bool>(component, true));
    for (map<Component*, bool>::iterator iterator = _componentSelections.begin(); iterator != _componentSelections.end(); iterator++) {
        if (component == iterator->first) {
            iterator->second = !iterator->second;
            setActionsEnabled(iterator->second);
        } else {
            iterator->second = false;
        }
    }
    _listener->updateUI();
}

void MindMapPresentationModel::setListener(MindMapPresentationModelChangeListener* listener)
{
    _listener = listener;
}


void MindMapPresentationModel::setActionsEnabled(bool enabled)
{
    _loadMindMapActionEnabled = enabled;
    _editNodeActionEnabled = enabled;
    _deleteNodeActionEnabled = enabled;
    _insertChildActionEnabled = enabled;
    _insertSiblingActionEnabled = enabled;
    _insertParentActionEnabled = enabled;
}

Component* MindMapPresentationModel::getSelectedComponent()
{
    return _selectedComponent;
}

void MindMapPresentationModel::editDescription(string description)
{
    _mindMapModel->editDescription(_selectedComponent, description);
    _listener->updateUI();
}

string MindMapPresentationModel::getSelectedComponentDescription()
{
    return _selectedComponent->getDescription();
}