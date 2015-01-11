#include "mind_map_view.h"
#include "qwindow.h"
#include "mind_map_presentation_model.h"
#include "node_graphics_item.h"
#include <list>
#include <vector>
#include "gui_display_visitor.h"

using namespace std;


MindMapView::MindMapView(QWidget* window, MindMapPresentationModel* mindMapPresentationModel)
{
    _graphicsScene = new QGraphicsScene(this);
    _mindMapPresentationModel = mindMapPresentationModel;
    setScene(_graphicsScene);
}

MindMapView::~MindMapView()
{
}

void MindMapView::refresh()
{
    _nodeGraphicsItems.clear();
    _graphicsScene->clear();
    viewport()->update();
    GUIDisplayVisitor guiDisplayVisitor(_graphicsScene, _nodeGraphicsItems, _mindMapPresentationModel);
    _mindMapPresentationModel->getMindMap()->accept(&guiDisplayVisitor);
}


void MindMapView::updateSelection()
{
    for (list<NodeGraphicsItem*>::iterator iterator = _nodeGraphicsItems.begin(); iterator != _nodeGraphicsItems.end(); iterator++) {
        NodeGraphicsItem* nodeGraphicsNode = *iterator;
        nodeGraphicsNode->setNodeSelected(_mindMapPresentationModel->getSelected(nodeGraphicsNode->getComponent()));
        nodeGraphicsNode->update();
    }
    viewport()->update();
}