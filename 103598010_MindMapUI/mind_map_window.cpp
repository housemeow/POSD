#include "mind_map_window.h"

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
    _createMindMapAction = new QAction(tr("Create a new mind map"), this);
    _createMindMapAction->setIcon(QIcon("Resources/new.png"));
    //_createMindMapAction->setShortcut(QKeySequence::New);
    _createMindMapAction->setStatusTip(tr("create a new mind map"));
    connect(_createMindMapAction, SIGNAL(triggered()), this, SLOT(createMindMap()));
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
    QMenu* fileMenu = _menuBar->addMenu(tr("File"));
    fileMenu->addAction(_createMindMapAction);
}

void MindMapWindow::createToolBar()
{
    _toolBar = new QToolBar(this);
    _toolBar->addAction(_createMindMapAction);
    addToolBar(Qt::TopToolBarArea, _toolBar);
}

void MindMapWindow::createMindMap()
{
    QMenu* editMenu = _menuBar->addMenu(tr("&Edit"));
    editMenu->addAction(_createMindMapAction);
}