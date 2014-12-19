#pragma once

#include "qgraphicsitem.h"
#include "component.h"
#include "mind_map_presentation_model.h"

enum MouseState {
    None,
    Click,
    DoubleClick
};

class NodeGraphicsItem :
    public QGraphicsItem
{
public:
    NodeGraphicsItem(MindMapPresentationModel* mindMapPresentationModel, Component* component);
    ~NodeGraphicsItem();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    //void setParentNodeGraphicsItem(NodeGraphicsItem* parentNodeGraphicsItem);
    bool isSelected();
    void setNodeSelected(bool selected);
    Component* getComponent();
    void click();
    static const int WIDTH;
    static const int HEIGHT;
    static const int PADDING;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event);
private:
    bool _selected;
    Component* _component;
    MindMapPresentationModel* _mindMapPresentationModel;
};

