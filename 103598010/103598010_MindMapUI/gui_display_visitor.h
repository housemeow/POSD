#pragma once
#include "component_visitor.h"
#include "mind_map_presentation_model.h"
#include "node_graphics_item.h"
#include "qgraphicsscene.h"
#include <list>

using namespace std;

class GUIDisplayVisitor :
    public ComponentVisitor
{
public:
    GUIDisplayVisitor(QGraphicsScene* graphicsScene, list<NodeGraphicsItem*>& nodeGraphicsItems, MindMapPresentationModel* mindMapPresentationModel);
    ~GUIDisplayVisitor();
    void visit(Node* node);
    void visit(Root* root);
    void visit(Component* component);
    int GUIDisplayVisitor::draw(Component* component, int xIndex, int& yIndex);
private :
    MindMapPresentationModel* _mindMapPresentationModel;
    list<NodeGraphicsItem*>& _nodeGraphicsItems;
    QGraphicsScene* _graphicsScene;
};

