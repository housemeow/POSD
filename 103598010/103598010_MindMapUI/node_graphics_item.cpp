#include "node_graphics_item.h"
#include <qpainter.h>
#include <qtimer.h>
#include <qapplication.h>
#include "mind_map_presentation_model.h"
#include <string>
#include <sstream>

using namespace std;

NodeGraphicsItem::NodeGraphicsItem(MindMapPresentationModel* mindMapPresentationModel, Component* component)
{
    _mindMapPresentationModel = mindMapPresentationModel;
    _component = component;
    _selected = false;
    setFlag(ItemIsSelectable);
}

NodeGraphicsItem::~NodeGraphicsItem()
{
}

Component* NodeGraphicsItem::getComponent()
{
    return _component;
}

QRectF NodeGraphicsItem::boundingRect() const
{
    return QRectF(0, 0, _component->getWidth(), _component->getHeight());
}

void NodeGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QRectF rect = boundingRect();
    if (_selected) {
        painter->setPen(QPen(Qt::red, 5));
    } else {
        painter->setPen(QPen(Qt::black, 3));
    }
    painter->drawRect(rect);
    painter->drawText(rect, Qt::AlignCenter, QString::fromStdString(_component->getBreakLineString()));// getString()));
}
bool NodeGraphicsItem::isSelected()
{
    return _selected;
}
void NodeGraphicsItem::click()
{
    _mindMapPresentationModel->clickNode(_component);
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
    _mindMapPresentationModel->doubleClick(_component);
    update();
}
void NodeGraphicsItem::setNodeSelected(bool selected)
{
    _selected = selected;
}