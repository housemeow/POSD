#ifndef MIND_MAP_WINDOW_H
#define MIND_MAP_WINDOW_H

#include "ui_mind_map_window.h"
#include "mind_map_presentation_model.h"
#include "mind_map_view.h"
#include "mind_map_presentation_model_change_observer.h"

class MindMapWindow : public QMainWindow, MindMapPresentationModelChangeObserver
{
    Q_OBJECT

public:
    MindMapWindow(MindMapPresentationModel* mindMapPresentationModel, QWidget* parent = 0);
    ~MindMapWindow();
    void showMessageBox(QString title, QString description);
private:
    MindMapPresentationModel* _mindMapPresentationModel;
    void createActions();
    void createUI();
    void createCentralWidget();
    void createMenuBar();
    void createToolBar();
    void updateUIState();
    void refreshUI();
    void doubleClick();

    QAction* _createMindMapAction;
    QAction* _openMindMapAction;
    QAction* _saveMindMapAction;
    QAction* _exitAction;
    QAction* _editNodeAction;
    QAction* _deleteNodeAction;
    QAction* _insertChildAction;
    QAction* _insertSiblingAction;
    QAction* _insertParentAction;
    QAction* _cutAction;
    QAction* _copyAction;
    QAction* _pasteAction;
    QAction* _aboutAction;
    QAction* _undoAction;
    QAction* _redoAction;
    QAction* _rectangleStyleAction;
    QAction* _triangleStyleAction;
    QAction* _ellipseStyleAction;
    QAction* _toggleCollapseAction;

    QWidget* _centralWidget;
    QMenuBar* _menuBar;
    QToolBar* _toolBar;
    MindMapView* _mindMapView;

private slots:
    void createMindMap();
    void openMindMap();
    void saveMindMap();
    void exit();
    void editNode();
    void deleteNode();
    void insertChild();
    void insertSibling();
    void insertParent();
    void cut();
    void copy();
    void paste();
    void about();
    void undo();
    void redo();
    void addRectangleStyle();
    void addTriangleStyle();
    void addEllipseStyle();
    void toggleCollapse();
};

#endif // MIND_MAP_WINDOW_H
