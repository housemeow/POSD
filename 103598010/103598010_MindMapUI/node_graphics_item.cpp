#include "node_graphics_item.h"
#include <qpainter.h>
#include <qtimer.h>
#include <qapplication.h>
#include "mind_map_presentation_model.h"
#include <string>
#include <sstream>
#include "gui_graphics.h"

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
    _component = NULL;
}

Component* NodeGraphicsItem::getComponent()
{
    return _component;
}

QRectF NodeGraphicsItem::boundingRect() const
{
    if (_component != NULL)
        return QRectF(0, 0, _component->getWidth(), _component->getHeight());
    return QRectF(0, 0, 0, 0);
}

void NodeGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QRectF rect = boundingRect();
    //else {
//       painter->setPen(QPen(Qt::black, 3));
//   }
    //
    GUIGraphics graphics(painter);
    _component->draw(&graphics);
    if (_selected) {
        painter->setPen(QPen(Qt::red, 5));
        painter->drawRect(rect);
    }
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
}

void NodeGraphicsItem::setNodeSelected(bool selected)
{
    _selected = selected;
}