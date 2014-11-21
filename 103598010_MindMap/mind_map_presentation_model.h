#pragma once
#include "mind_map_model.h"
#include <string>
#include <map>
#include "mind_map_presentation_model_change_listener.h"

using namespace std;

class MindMapPresentationModel
{
public:
    MindMapPresentationModel(MindMapModel* mindMapModel);
    ~MindMapPresentationModel();
    Component* getMindMap();
    void createMindMap(string);
    void loadMindMap(string filePath);
    bool getSaveMindMapActionEnabled();
    bool getEditNodeActionEnabled();
    bool getDeleteNodeActionEnabled();
    bool getInsertChildActionEnabled();
    bool getInsertSiblingActionEnabled();
    bool getInsertParentActionEnabled();
    bool getSelected(Component*);
    void clickNode(Component*);
    void setListener(MindMapPresentationModelChangeListener* listener);
    Component* getSelectedComponent();
    void editDescription(string description);
    string getSelectedComponentDescription();
    void deleteComponent();
    void saveMindMap(string fileName);
    void doubleClick(Component* component);
    void insertChild(string description);
    void insertSibling(string description);
    void insertParentNode(string description);
private:
    void setActionsEnabled(bool enabled);
    map<Component*, bool> _componentSelections;
    MindMapModel* _mindMapModel;
    bool _saveMindMapActionEnabled;
    bool _editNodeActionEnabled;
    bool _deleteNodeActionEnabled;
    bool _insertChildActionEnabled;
    bool _insertSiblingActionEnabled;
    bool _insertParentActionEnabled;
    MindMapPresentationModelChangeListener* _listener;
    Component* _selectedComponent;
};

