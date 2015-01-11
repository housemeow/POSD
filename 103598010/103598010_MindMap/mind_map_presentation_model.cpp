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
    _saveMindMapActionEnabled = false;
    _selectedComponent = NULL;
    _clipboardComponent = NULL;
}

MindMapPresentationModel::MindMapPresentationModel()
{
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
    _saveMindMapActionEnabled = true;
}

void MindMapPresentationModel::loadMindMap(string filePath)
{
    _mindMapModel->loadMindMap(filePath);
    setActionsEnabled(false);
    updateUIState();
    _saveMindMapActionEnabled = true;
}

bool MindMapPresentationModel::getSaveMindMapActionEnabled()
{
    return _saveMindMapActionEnabled;
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

bool MindMapPresentationModel::getCutActionEnabled()
{
    return _cutActionEnabled;
}

bool MindMapPresentationModel::getCopyActionEnabled()
{
    return _copyActionEnabled;
}

bool MindMapPresentationModel::getPasteActionEnabled()
{
    return _pasteActionEnabled;
}

bool MindMapPresentationModel::getUndoActionEnabled()
{
    return _mindMapModel->getUndoCount() > 0;
}

bool MindMapPresentationModel::getRedoActionEnabled()
{
    return _mindMapModel->getRedoCount() > 0;
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
    _cutActionEnabled = false;
    _copyActionEnabled = false;
    _pasteActionEnabled = false;
    _selectedComponent = component;
    _componentSelections.insert(pair<Component*, bool>(component, false));
    for (map<Component*, bool>::iterator iterator = _componentSelections.begin(); iterator != _componentSelections.end(); iterator++) {
        if (component == iterator->first) {
            iterator->second = !iterator->second;
            setActionsEnabled(iterator->second);
            bool selected = iterator->second;
            bool isRoot = component == _mindMapModel->getMindMap();
            _cutActionEnabled = selected && !isRoot;
            _copyActionEnabled = selected && !isRoot;
            _pasteActionEnabled = selected && _clipboardComponent != NULL;
        } else {
            iterator->second = false;
        }
    }
    updateUIState();
}



void MindMapPresentationModel::setActionsEnabled(bool enabled)
{
    _editNodeActionEnabled = enabled;
    _deleteNodeActionEnabled = enabled;
    _insertChildActionEnabled = enabled;
    _insertSiblingActionEnabled = enabled;
    _insertParentActionEnabled = enabled;
    _cutActionEnabled = enabled;
    _copyActionEnabled = enabled;
    _pasteActionEnabled = enabled;
}

Component* MindMapPresentationModel::getSelectedComponent()
{
    return _selectedComponent;
}

void MindMapPresentationModel::editDescription(string description)
{
    _mindMapModel->editDescription(_selectedComponent, description);
    updateUIState();
    refreshUI();
}

string MindMapPresentationModel::getSelectedComponentDescription()
{
    return _selectedComponent->getDescription();
}

void MindMapPresentationModel::deleteComponent()
{
    _mindMapModel->deleteComponentCommand(_selectedComponent);
    setActionsEnabled(false);
    _selectedComponent = NULL;
    _componentSelections.clear();
    updateUIState();
    refreshUI();
}

void MindMapPresentationModel::saveMindMap(string fileName)
{
    _mindMapModel->saveMindMap(fileName);
}

void MindMapPresentationModel::doubleClick(Component* component)
{
    _componentSelections.insert(pair<Component*, bool>(component, false));
    for (map<Component*, bool>::iterator iterator = _componentSelections.begin(); iterator != _componentSelections.end(); iterator++) {
        if (component == iterator->first) {
            iterator->second = true;
            setActionsEnabled(iterator->second);
        } else {
            iterator->second = false;
        }
    }
    triggerDoubleClick();
    updateUIState();
}

void MindMapPresentationModel::insertChild(string description)
{
    _mindMapModel->insertChildNodeCommand(_selectedComponent, description);
    setActionsEnabled(false);
    updateUIState();
    refreshUI();
}


void MindMapPresentationModel::insertSibling(string description)
{
    _mindMapModel->insertSiblingNodeCommand(_selectedComponent, description);
    setActionsEnabled(false);
    updateUIState();
    refreshUI();
}

void MindMapPresentationModel::insertParentNode(string description)
{
    _mindMapModel->insertParentNodeCommand(_selectedComponent, description);
    setActionsEnabled(false);
    updateUIState();
    refreshUI();
}


void MindMapPresentationModel::cut()
{
    delete _clipboardComponent;
    _clipboardComponent = _selectedComponent->clone();
    _clipboardComponent->setParent(NULL);
    _mindMapModel->deleteComponentTree(_selectedComponent);
    setActionsEnabled(false);
    _pasteActionEnabled = true;
    _selectedComponent = NULL;
    _componentSelections.clear();
    updateUIState();
    refreshUI();
}

void MindMapPresentationModel::copy()
{
    delete _clipboardComponent;
    _clipboardComponent = _selectedComponent->clone();
    _clipboardComponent->setParent(NULL);
    _pasteActionEnabled = true;
    updateUIState();
}

void MindMapPresentationModel::paste()
{
    Component* component = _clipboardComponent->clone();
    _selectedComponent->addChild(component);
    setActionsEnabled(false);
    _selectedComponent = NULL;
    _componentSelections.clear();
    updateUIState();
    refreshUI();
}
void MindMapPresentationModel::undo()
{
    _mindMapModel->undo();
    updateUIState();
    refreshUI();
}

void MindMapPresentationModel::redo()
{
    _mindMapModel->redo();
    updateUIState();
    refreshUI();
}