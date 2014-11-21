#ifndef MIND_MAP_WINDOW_H
#define MIND_MAP_WINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_mind_map_window.h"

class MindMapWindow : public QMainWindow
{
    Q_OBJECT

public:
    MindMapWindow(QWidget* parent = 0);
    ~MindMapWindow();
private:
    void createActions();
    void createUI();
    void createCentralWidget();
    void createMenuBar();
    void createToolBar();

    QAction* _createMindMapAction;
    QAction* _openMindMapAction;
    QAction* _saveMindMapAction;
    QAction* _editNodeAction;
    QAction* _deleteNodeAction;
    QAction* _insertChildAction;
    QAction* _insertSiblingAction;
    QAction* _insertParentAction;
    QAction* _aboutAction;

    QWidget* _centralWidget;
    QMenuBar* _menuBar;
    QToolBar* _toolBar;
private slots:
    void createMindMap();
    void openMindMap();
    void saveMindMap();
    void editNode();
    void deleteNode();
    void insertChild();
    void insertSibling();
    void insertParent();
    void about();
};

#endif // MIND_MAP_WINDOW_H
