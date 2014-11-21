#include <qmessagebox.h>
#include <qinputdialog.h>
#include <QtWidgets/QMainWindow>
#include "mind_map_model.h"
#include "mind_map_presentation_model.h"
#include "mind_map_window.h"
#include "qgraphicsview.h"
#include "node_graphics_item.h"
#include "mind_map_view.h"
#include "qfiledialog.h"

MindMapWindow::MindMapWindow(MindMapPresentationModel* mindMapPresentationModel, QWidget* parent)
    : QMainWindow(parent)//, MindMapPresentationModelChangeListener()
{
    //ui.setupUi(this);
    _mindMapPresentationModel = mindMapPresentationModel;
    _mindMapPresentationModel->setListener(this);
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
    updateUIState();
}

void MindMapWindow::createActions()
{
    // create mind map action
    _createMindMapAction = new QAction(tr("Create a new mind map"), this);
    _createMindMapAction->setIcon(QIcon("Resources\\new.png"));
    _createMindMapAction->setStatusTip(tr("create a new mind map"));
    connect(_createMindMapAction, SIGNAL(triggered()), this, SLOT(createMindMap()));
    // open mind map action
    _openMindMapAction = new QAction(tr("Open a new mind map"), this);
    _openMindMapAction->setIcon(QIcon("Resources\\open.png"));
    _openMindMapAction->setStatusTip(tr("open a new mind map"));
    connect(_openMindMapAction, SIGNAL(triggered()), this, SLOT(openMindMap()));
    // save mind map action
    _saveMindMapAction = new QAction(tr("Save a new mind map"), this);
    _saveMindMapAction->setIcon(QIcon("Resources\\save.png"));
    _saveMindMapAction->setStatusTip(tr("save a new mind map"));
    connect(_saveMindMapAction, SIGNAL(triggered()), this, SLOT(saveMindMap()));
    // exit action
    _exitAction = new QAction(tr("Exit"), this);
    _exitAction->setIcon(QIcon("Resources\\delete.png"));
    _exitAction->setStatusTip(tr("Exit"));
    connect(_exitAction, SIGNAL(triggered()), this, SLOT(exit()));
    // edit node action
    _editNodeAction = new QAction(tr("& Edit"), this);
    _editNodeAction->setIcon(QIcon("Resources\\edit.png"));
    _editNodeAction->setStatusTip(tr("Edit a node"));
    connect(_editNodeAction, SIGNAL(triggered()), this, SLOT(editNode()));
    // delete node action
    _deleteNodeAction = new QAction(tr("& Delete"), this);
    _deleteNodeAction->setIcon(QIcon("Resources\\delete.png"));
    _deleteNodeAction->setStatusTip(tr("Delete a node"));
    connect(_deleteNodeAction, SIGNAL(triggered()), this, SLOT(deleteNode()));
    // insert child action
    _insertChildAction = new QAction(tr("Insert a& Child"), this);
    _insertChildAction->setIcon(QIcon("Resources\\insertChild.png"));
    _insertChildAction->setStatusTip(tr("Insert a child"));
    connect(_insertChildAction, SIGNAL(triggered()), this, SLOT(insertChild()));
    // insert sibling action
    _insertSiblingAction = new QAction(tr("Insert a& Sibling"), this);
    _insertSiblingAction->setIcon(QIcon("Resources\\insertSibling.png"));
    _insertSiblingAction->setStatusTip(tr("Insert a sibling"));
    connect(_insertSiblingAction, SIGNAL(triggered()), this, SLOT(insertSibling()));
    // insert parent action
    _insertParentAction = new QAction(tr("Insert a& Parent"), this);
    _insertParentAction->setIcon(QIcon("Resources\\insertParent.png"));
    _insertParentAction->setStatusTip(tr("Insert a parent"));
    connect(_insertParentAction, SIGNAL(triggered()), this, SLOT(insertParent()));
    // about action
    _aboutAction = new QAction("About", this);
    connect(_aboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MindMapWindow::createCentralWidget()
{
    _mindMapView = new MindMapView(this, _mindMapPresentationModel);
    setCentralWidget(_mindMapView);
    _mindMapPresentationModel->createMindMap("hello");
    _mindMapPresentationModel->insertNewNode(_mindMapPresentationModel->getMindMap(), "something", InsertNodeMode::InsertNodeModeChild);
    _mindMapView->refresh();
}

void MindMapWindow::createMenuBar()
{
    _menuBar = new QMenuBar(this);
    QMenu* fileMenu = _menuBar->addMenu(tr("& File"));
    fileMenu->addAction(_createMindMapAction);
    fileMenu->addAction(_openMindMapAction);
    fileMenu->addAction(_saveMindMapAction);
    fileMenu->addAction(_exitAction);
    QMenu* edit = _menuBar->addMenu(tr("& Edit"));
    edit->addAction(_editNodeAction);
    edit->addAction(_deleteNodeAction);
    edit->addAction(_insertChildAction);
    edit->addAction(_insertSiblingAction);
    edit->addAction(_insertParentAction);
    QMenu* help = _menuBar->addMenu("& Help");
    help->addAction(_aboutAction);
    this->setMenuBar(_menuBar);
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
    _mindMapPresentationModel->createMindMap("");
    _mindMapView->refresh();
}


void MindMapWindow::openMindMap()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                       tr("Open mind map"), ".", tr("Image Files (*.mm)"));
    try {
        _mindMapPresentationModel->loadMindMap(fileName.toUtf8().constData());
    } catch (exception exception) {
        showMessageBox("Exception", exception.what());
    }
    _mindMapView->refresh();
}

void MindMapWindow::exit()
{
    close();
}

void MindMapWindow::updateUIState()
{
    _saveMindMapAction->setEnabled(_mindMapPresentationModel->getSaveMindMapActionEnabled());
    _editNodeAction->setEnabled(_mindMapPresentationModel->getEditNodeActionEnabled());
    _deleteNodeAction->setEnabled(_mindMapPresentationModel->getDeleteNodeActionEnabled());
    _insertChildAction->setEnabled(_mindMapPresentationModel->getInsertChildActionEnabled());
    _insertSiblingAction->setEnabled(_mindMapPresentationModel->getInsertSiblingActionEnabled());
    _insertParentAction->setEnabled(_mindMapPresentationModel->getInsertParentActionEnabled());
    _mindMapView->updateSelection();
}

void MindMapWindow::saveMindMap()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                       tr("Save mind map"), ".", tr("Image Files (*.mm)"));
    try {
        _mindMapPresentationModel->saveMindMap(fileName.toUtf8().constData());
    } catch (exception exception) {
        showMessageBox("Exception", exception.what());
    }
}

void MindMapWindow::editNode()
{
    bool ok;
    QString description = QInputDialog::getText(this, tr("Input Dialog"),
                          tr("Please input your description"), QLineEdit::Normal,
                          QString::fromStdString(_mindMapPresentationModel->getSelectedComponentDescription()), &ok);
    if (ok && !description.isEmpty()) {
        _mindMapPresentationModel->editDescription(description.toUtf8().constData());
    }
}

void MindMapWindow::deleteNode()
{
    try {
        _mindMapPresentationModel->deleteComponent();
    } catch (exception exception) {
        showMessageBox("Exception", exception.what());
    }
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
    showMessageBox("About", "103598010\nKellyang\n2014NTUT POST\nVersion 4.0.0");
}

void MindMapWindow::showMessageBox(QString title, QString description)
{
    QMessageBox message(QMessageBox::Information, title, description, QMessageBox::Ok, NULL);
    message.exec();
}

void MindMapWindow::refreshUI()
{
    _mindMapView->refresh();
}

void MindMapWindow::doubleClick()
{
    editNode();
}