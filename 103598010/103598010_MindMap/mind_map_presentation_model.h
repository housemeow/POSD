#pragma once
#include "mind_map_model.h"
#include <string>
#include <map>
#include "mind_map_presentation_model_change_subject.h"

using namespace std;

class MindMapPresentationModel: public MindMapPresentationModelChangeSubject
{
public:
    MindMapPresentationModel(MindMapModel* mindMapModel);
    MindMapPresentationModel();
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
    bool getCutActionEnabled();
    bool getCopyActionEnabled();
    bool getPasteActionEnabled();
    bool getUndoActionEnabled();
    bool getRedoActionEnabled();
    bool getSelected(Component*);
    void clickNode(Component*);
    Component* getSelectedComponent();
    void editDescription(string description);
    string getSelectedComponentDescription();
    void deleteComponent();
    void saveMindMap(string fileName);
    void doubleClick(Component* component);
    void insertChild(string description);
    void insertSibling(string description);
    void insertParentNode(string description);
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();
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
    bool _cutActionEnabled;
    bool _copyActionEnabled;
    bool _pasteActionEnabled;
    Component* _selectedComponent;
    Component* _clipboardComponent;
};

