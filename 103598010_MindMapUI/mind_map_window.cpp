#include "mind_map_window.h"
#include <qmessagebox.h>

MindMapWindow::MindMapWindow(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);
    resize(600, 400);
    createActions();
    createUI();
}

MindMapWindow::~MindMapWindow()
{
}


void MindMapWindow::createUI()
{
    createCentralWidget();
    createMenuBar();
    createToolBar();
}

void MindMapWindow::createActions()
{
    // create mind map action
    _createMindMapAction = new QAction(tr("Create a new mind map"), this);
    _createMindMapAction->setIcon(QIcon("Resources/new.png"));
    _createMindMapAction->setStatusTip(tr("create a new mind map"));
    connect(_createMindMapAction, SIGNAL(triggered()), this, SLOT(createMindMap()));
    // open mind map action
    _openMindMapAction = new QAction(tr("Open a new mind map"), this);
    _openMindMapAction->setIcon(QIcon("Resources/open.png"));
    _openMindMapAction->setStatusTip(tr("open a new mind map"));
    connect(_openMindMapAction, SIGNAL(triggered()), this, SLOT(openMindMap()));
    // save mind map action
    _saveMindMapAction = new QAction(tr("Save a new mind map"), this);
    _saveMindMapAction->setIcon(QIcon("Resources/save.png"));
    _saveMindMapAction->setStatusTip(tr("save a new mind map"));
    connect(_saveMindMapAction, SIGNAL(triggered()), this, SLOT(saveMindMap()));
    // edit node action
    _editNodeAction = new QAction(tr("&Edit"), this);
    _editNodeAction->setIcon(QIcon("Resources/edit.png"));
    _editNodeAction->setStatusTip(tr("Edit a node"));
    connect(_editNodeAction, SIGNAL(triggered()), this, SLOT(editNode()));
    // delete node action
    _deleteNodeAction = new QAction(tr("&Delete"), this);
    _deleteNodeAction->setIcon(QIcon("Resources/delete.png"));
    _deleteNodeAction->setStatusTip(tr("Delete a node"));
    connect(_deleteNodeAction, SIGNAL(triggered()), this, SLOT(deleteNode()));
    // insert child action
    _insertChildAction = new QAction(tr("Insert a &Child"), this);
    _insertChildAction->setIcon(QIcon("Resources/insertChild.png"));
    _insertChildAction->setStatusTip(tr("Insert a child"));
    connect(_insertChildAction, SIGNAL(triggered()), this, SLOT(insertChild()));
    // insert sibling action
    _insertSiblingAction = new QAction(tr("Insert a &Sibling"), this);
    _insertSiblingAction->setIcon(QIcon("Resources/insertSibling.png"));
    _insertSiblingAction->setStatusTip(tr("Insert a sibling"));
    connect(_insertSiblingAction, SIGNAL(triggered()), this, SLOT(insertSibling()));
    // insert parent action
    _insertParentAction = new QAction(tr("Insert a &Parent"), this);
    _insertParentAction->setIcon(QIcon("Resources/insertParent.png"));
    _insertParentAction->setStatusTip(tr("Insert a parent"));
    connect(_insertParentAction, SIGNAL(triggered()), this, SLOT(insertParent()));
    // about action
    _aboutAction = new QAction("About", this);
    connect(_aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MindMapWindow::createCentralWidget()
{
    _centralWidget = new QWidget(this);
    setCentralWidget(_centralWidget);
}

void MindMapWindow::createMenuBar()
{
    _menuBar = new QMenuBar(_centralWidget);
    _menuBar->setGeometry(0, 0, 600, 20);
    QMenu* fileMenu = _menuBar->addMenu(tr("&File"));
    fileMenu->addAction(_createMindMapAction);
    _menuBar->setGeometry(0, 0, 600, 20);
    QMenu* edit = _menuBar->addMenu(tr("&Edit"));
    edit->addAction(_editNodeAction);
    edit->addAction(_deleteNodeAction);
    edit->addAction(_insertChildAction);
    edit->addAction(_insertSiblingAction);
    edit->addAction(_insertParentAction);
    QMenu* help = _menuBar->addMenu("&Help");
    help->addAction(_aboutAction);
}

void MindMapWindow::createToolBar()
{
    _toolBar = new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, _toolBar);
    _toolBar->addAction(_createMindMapAction);
    _toolBar->addAction(_openMindMapAction);
    _toolBar->addAction(_saveMindMapAction);
    _toolBar->addSeparator();
    _toolBar->addAction(_editNodeAction);
    _toolBar->addAction(_deleteNodeAction);
    _toolBar->addSeparator();
    _toolBar->addAction(_insertChildAction);
    _toolBar->addAction(_insertSiblingAction);
    _toolBar->addAction(_insertParentAction);
}

void MindMapWindow::createMindMap()
{
    //QMenu* editMenu = _menuBar->addMenu(tr("&Edit"));
    //editMenu->addAction(_createMindMapAction);
}


void MindMapWindow::openMindMap()
{
}

void MindMapWindow::saveMindMap()
{
}

void MindMapWindow::editNode()
{
}

void MindMapWindow::deleteNode()
{
}

void MindMapWindow::insertChild()
{
}

void MindMapWindow::insertSibling()
{
}

void MindMapWindow::insertParent()
{
}

void MindMapWindow::about()
{
    QMessageBox message(QMessageBox::Information, "About", "103598010\nKellyang\nVersion 4.0.0", QMessageBox::Ok, NULL);
    message.exec();
}
