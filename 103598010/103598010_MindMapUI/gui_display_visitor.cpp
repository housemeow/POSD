#include "gui_display_visitor.h"
#include "node_graphics_item.h"


GUIDisplayVisitor::GUIDisplayVisitor(QGraphicsScene* graphicsScene, list<NodeGraphicsItem*>& nodeGraphicsItems, MindMapPresentationModel* mindMapPresentationModel) : _nodeGraphicsItems(nodeGraphicsItems)
{
    _graphicsScene = graphicsScene;
    _mindMapPresentationModel = mindMapPresentationModel;
}

GUIDisplayVisitor::~GUIDisplayVisitor()
{
}

void GUIDisplayVisitor::visit(Node* node)
{
    visit((Component*)node);
}

void GUIDisplayVisitor::visit(Root* root)
{
    visit((Component*)root);
}

void GUIDisplayVisitor::visit(Component* component)
{
    vector<int> layerCounter;
    int y = 0;
    draw(component, 0, y);
}

int GUIDisplayVisitor::draw(Component* component, int xIndex, int& yIndex)
{
    int x = xIndex * (Component::MAX_WIDTH_PIXEL + Component::PADDING);
    int y = yIndex * (Component::MAX_HEIGHT_PIXEL + Component::PADDING);
    int middleY = y + component->getHeight() / 2;
    list<Component*> children = component->getNodeList();
    list<int> childrenMiddleY;
    // traversal
    if (!component->isCollapse()) {
        for (list<Component*>::iterator iterator = children.begin(); iterator != children.end(); iterator++) {
            Component* child = *iterator;
            int childMiddleY = draw(child, xIndex + 1, yIndex);
            childrenMiddleY.push_back(childMiddleY);
        }
    }
    // create self GraphicsItem
    NodeGraphicsItem* nodeGraphicsItem = new NodeGraphicsItem(_mindMapPresentationModel, component);
    if (children.size() == 0) {
        yIndex++;
    } else {
        // calc average line
        middleY = 0;
        for (list<int>::iterator iterator = childrenMiddleY.begin(); iterator != childrenMiddleY.end(); iterator++) {
            middleY += ((float) * iterator) / childrenMiddleY.size();
        }
        // create line between self and child
        for (list<int>::iterator iterator = childrenMiddleY.begin(); iterator != childrenMiddleY.end(); iterator++) {
            int rightX = x + nodeGraphicsItem->boundingRect().right();
            int leftX = x + nodeGraphicsItem->boundingRect().left();
            QGraphicsLineItem* line = new QGraphicsLineItem(rightX, middleY, leftX + Component::MAX_WIDTH_PIXEL + Component::PADDING, *iterator);
            _graphicsScene->addItem(line);
        }
    }
    nodeGraphicsItem->setPos(x, middleY - component->getHeight() / 2);
    component->setX(0);
    component->setY(0);
    _nodeGraphicsItems.push_back(nodeGraphicsItem);
    _graphicsScene->addItem(nodeGraphicsItem);
    return middleY;
}
