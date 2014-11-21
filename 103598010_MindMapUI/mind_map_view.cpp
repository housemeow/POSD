#include "mind_map_view.h"
#include "qwindow.h"
#include "mind_map_presentation_model.h"
#include "node_graphics_item.h"
#include <list>
#include <vector>

using namespace std;


MindMapView::MindMapView(QWidget* window, MindMapPresentatinoModel* mindMapPresentationModel)
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
    _graphicsScene->clear();
    viewport()->update();
    vector<int> layerCounter;
    addNode(layerCounter, NULL, _mindMapPresentationModel->getMindMap(), 0, 0);
}

void MindMapView::addNode(vector<int>& layerCounter, NodeGraphicsItem* parentGraphicsItem, Component* component, int xIndex, int yIndex)
{
    if (component != NULL) {
        if (layerCounter.size() == xIndex) {
            layerCounter.push_back(0);
        } else {
            ++layerCounter[xIndex];
        }
        yIndex = layerCounter[xIndex];
        NodeGraphicsItem* nodeGraphicsItem = new NodeGraphicsItem(component);
        _nodeGraphicsItems.push_back(nodeGraphicsItem);
        if (parentGraphicsItem) {
            nodeGraphicsItem->setParentNodeGraphicsItem(parentGraphicsItem);
        }
        int x = xIndex * (NodeGraphicsItem::WIDTH + NodeGraphicsItem::PADDING);
        int y = yIndex * (NodeGraphicsItem::HEIGHT + NodeGraphicsItem::PADDING);
        nodeGraphicsItem->setPos(x, y);
        _graphicsScene->addItem(nodeGraphicsItem);
        for (list<Component*>::iterator iterator = component->getNodeList().begin(), end = component->getNodeList().end(); iterator != end; ++iterator) {
            Component* child = *iterator;
            addNode(layerCounter, nodeGraphicsItem, child, xIndex + 1, yIndex);
        }
    }
}