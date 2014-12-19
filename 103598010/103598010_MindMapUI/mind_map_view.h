#pragma once
#include <qgraphicsview.h>
#include "mind_map_presentation_model.h"
#include "node_graphics_item.h"

class MindMapView: public QGraphicsView
{
public:
    MindMapView(QWidget* window, MindMapPresentationModel* mindMapPresentationModel);
    ~MindMapView();
    void refresh();
    int draw(Component* component, int x, int& y);
    void updateSelection();
private:
    QGraphicsScene* _graphicsScene;
    MindMapPresentationModel* _mindMapPresentationModel;
    list<NodeGraphicsItem*> _nodeGraphicsItems;
};

