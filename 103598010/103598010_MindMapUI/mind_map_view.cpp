#include "mind_map_view.h"
#include "qwindow.h"
#include "mind_map_presentation_model.h"
#include "node_graphics_item.h"
#include <list>
#include <vector>

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
    vector<int> layerCounter;
    int y = 0;
    draw(_mindMapPresentationModel->getMindMap(), 0, y);
}

int MindMapView::draw(Component* component, int xIndex, int& yIndex)
{
    int middleY = 0;
    int x = xIndex * (NodeGraphicsItem::MAX_WIDTH + NodeGraphicsItem::PADDING);
    list<Component*> children = component->getNodeList();
    list<int> childrenMiddleY;
    // traversal
    for (list<Component*>::iterator iterator = children.begin(); iterator != children.end(); iterator++) {
        Component* child = *iterator;
        int childMiddleY = draw(child, xIndex + 1, yIndex);
        childrenMiddleY.push_back(childMiddleY);
    }
    // create self GraphicsItem
    NodeGraphicsItem* nodeGraphicsItem = new NodeGraphicsItem(_mindMapPresentationModel, component);
    if (children.size() == 0) {
        int y = yIndex * (NodeGraphicsItem::MAX_HEIGHT + NodeGraphicsItem::PADDING);
        middleY = y + NodeGraphicsItem::MAX_HEIGHT / 2;
        yIndex++;
    } else {
        // calc average line
        for (list<int>::iterator iterator = childrenMiddleY.begin(); iterator != childrenMiddleY.end(); iterator++) {
            middleY += ((float) * iterator) / childrenMiddleY.size();
        }
        // create line between self and child
        for (list<int>::iterator iterator = childrenMiddleY.begin(); iterator != childrenMiddleY.end(); iterator++) {
            int rightX = x + nodeGraphicsItem->boundingRect().right();
            int leftX = x + nodeGraphicsItem->boundingRect().left();
            QGraphicsLineItem* line = new QGraphicsLineItem(rightX, middleY, leftX + NodeGraphicsItem::MAX_WIDTH + NodeGraphicsItem::PADDING, *iterator);
            _graphicsScene->addItem(line);
        }
    }
    nodeGraphicsItem->setPos(x, middleY - NodeGraphicsItem::MAX_HEIGHT / 2);
    _nodeGraphicsItems.push_back(nodeGraphicsItem);
    _graphicsScene->addItem(nodeGraphicsItem);
    return middleY;
}

void MindMapView::updateSelection()
{
    for (list<NodeGraphicsItem*>::iterator iterator = _nodeGraphicsItems.begin(); iterator != _nodeGraphicsItems.end(); iterator++) {
        NodeGraphicsItem* nodeGraphicsNode = *iterator;
        nodeGraphicsNode->setNodeSelected(_mindMapPresentationModel->getSelected(nodeGraphicsNode->getComponent()));
    }
    viewport()->update();
}