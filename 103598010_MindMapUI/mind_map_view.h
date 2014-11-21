#pragma once
#include <qgraphicsview.h>
#include "mind_map_presentation_model.h"
#include "node_graphics_item.h"

class MindMapView: public QGraphicsView
{
public:
    MindMapView(QWidget* window, MindMapPresentatinoModel* mindMapPresentationModel);
    ~MindMapView();
    void refresh();
    void addNode(vector<int>& layerCounter, NodeGraphicsItem* parentGraphicsItem, Component* component, int x, int y);
private:
    QGraphicsScene* _graphicsScene;
    MindMapPresentatinoModel* _mindMapPresentationModel;
    list<NodeGraphicsItem*> _nodeGraphicsItems;
};

