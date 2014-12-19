#include "node_graphics_item.h"
#include <qpainter.h>
#include <qtimer.h>
#include <qapplication.h>
#include "mind_map_presentation_model.h"
#include <string>
#include <sstream>

using namespace std;

const int NodeGraphicsItem::WIDTH = 80;
const int NodeGraphicsItem::HEIGHT = 40;
const int NodeGraphicsItem::MAX_WIDTH = 120;
const int NodeGraphicsItem::MAX_HEIGHT = 60;
const int NodeGraphicsItem::PADDING = 20;

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

string NodeGraphicsItem::getString() const
{
    istringstream iss(_component->getDescription());
    vector<string> tokens { istream_iterator<string>{iss},
                            istream_iterator<string>{}
                          };
    vector<string> processedString;
    for (vector<string>::iterator iterator = tokens.begin(); iterator != tokens.end(); iterator++) {
        if (processedString.empty()) {
            processedString.push_back(*iterator);
        } else {
            if (getPixelWide(processedString.back() + *iterator) < MAX_WIDTH) {
                string back = processedString.back() + " " + *iterator;
                processedString.pop_back();
                processedString.push_back(back);
            } else {
                processedString.push_back(*iterator);
            }
        }
        string str = getConcatenationString(processedString);
        int high = getPixelHigh(str);
        if (getLineHeight(str) > MAX_HEIGHT) {
            string back = processedString.back() + "...";
            processedString.pop_back();
            processedString.push_back(back);
            break;
        }
    }
    return getConcatenationString(processedString);
}
string NodeGraphicsItem::getConcatenationString(vector<string> strings) const
{
    if (strings.empty()) {
        return "";
    } else {
        string str = strings.back();
        strings.pop_back();
        while (!strings.empty()) {
            str = strings.back() + "\n" + str;
            strings.pop_back();
        }
        return str;
    }
}
int NodeGraphicsItem::getPixelWide(string str) const
{
    QFont font;
    QFontMetrics fm(font);
    return fm.width(QString::fromStdString(str)) + PADDING;
}
int NodeGraphicsItem::getPixelHigh(string str) const
{
    QFont font;
    QFontMetrics fm(font);
    fm.width(QString::fromStdString(str));
    return fm.boundingRect(QString::fromStdString(str)).height();
}
QRectF NodeGraphicsItem::boundingRect() const
{
    QFont font;
    QFontMetrics fm(font);
    string str = getString();
    QRect bound = fm.boundingRect(QString::fromStdString(str));
    int pixelsWide = fm.width(QString::fromStdString(getString())) + PADDING;
    int pixelHeight = getLineHeight(str);
    int height = pixelHeight < HEIGHT ? HEIGHT : pixelHeight < MAX_HEIGHT ? pixelHeight : MAX_HEIGHT;
    return QRectF(0, 0, pixelsWide < MAX_WIDTH ? pixelsWide : MAX_WIDTH, height + PADDING);// getLineHeight(str));
}
int NodeGraphicsItem::getLineHeight(string str) const
{
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    QFont font;
    QFontMetrics fm(font);
    QRect bound = fm.boundingRect(QString::fromStdString(str));
    return bound.height() * (count + 1);
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
    painter->drawText(rect, Qt::AlignCenter, QString::fromStdString(getString()));
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