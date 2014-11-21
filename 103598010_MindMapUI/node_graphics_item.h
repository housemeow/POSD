#pragma once

#include "qgraphicsitem.h"
#include "component.h"

enum MouseState {
    None,
    Click,
    DoubleClick
};

class NodeGraphicsItem :
    public QGraphicsItem
{
public:
    NodeGraphicsItem(Component* component);
    ~NodeGraphicsItem();

    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    void setParentNodeGraphicsItem(NodeGraphicsItem* parentNodeGraphicsItem);
    bool isSelected();
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
    MouseState _mouseState;
    NodeGraphicsItem* _parentNodeGraphicsItem;
};

