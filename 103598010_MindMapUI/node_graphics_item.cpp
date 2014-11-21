#include "node_graphics_item.h"
#include <qpainter.h>
#include <qtimer.h>
#include <qapplication.h>

const int NodeGraphicsItem::WIDTH = 80;
const int NodeGraphicsItem::HEIGHT = 40;
const int NodeGraphicsItem::PADDING = 20;

NodeGraphicsItem::NodeGraphicsItem(Component* component)
{
    _component = component;
    _selected = false;
    //setFlag(ItemIsMovable);
    //setFlag(ItemIsFocusable);
    setFlag(ItemIsSelectable);
    _mouseState = MouseState::None;
    _parentNodeGraphicsItem = NULL;
}

NodeGraphicsItem::~NodeGraphicsItem()
{
}

Component* NodeGraphicsItem::getComponent()
{
    return _component;
}

void NodeGraphicsItem::setParentNodeGraphicsItem(NodeGraphicsItem* parentNodeGraphicsItem)
{
    _parentNodeGraphicsItem = parentNodeGraphicsItem;
}


QRectF NodeGraphicsItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void NodeGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QRectF rect = boundingRect();
    if (_selected) {
        QPen pen(Qt::red, 5);
        painter->setPen(pen);
    } else {
        QPen pen(Qt::black, 3);
        painter->setPen(pen);
    }
    painter->drawRect(rect);
    painter->drawText(rect, Qt::AlignCenter, QString::fromStdString(_component->getDescription()));
    if (_parentNodeGraphicsItem) {
        QRectF sceneRect = sceneBoundingRect();
        QRectF parentSceneRect = _parentNodeGraphicsItem->sceneBoundingRect();
        qreal x = 0;
        qreal y = HEIGHT / 2;
        qreal parentOffsetX = parentSceneRect.right() - sceneRect.left();
        qreal middleY = (sceneRect.top() + sceneRect.bottom()) / 2;
        qreal parentMiddleY = (parentSceneRect.top() + parentSceneRect.bottom()) / 2;
        qreal parentOffsetY = parentMiddleY - middleY;
        painter->drawLine(x, y, x + parentOffsetX, y + parentOffsetY);
    }
}

bool NodeGraphicsItem::isSelected()
{
    return _selected;
}

void NodeGraphicsItem::click()
{
    _selected = !_selected;
}


void NodeGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    update();
    click();
    QGraphicsItem::mousePressEvent(event);
}

void NodeGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

void NodeGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
    _selected = true;
    update();
}