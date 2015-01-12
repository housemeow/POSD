#pragma once
#include "component.h"

class ComponentDecorator: public Component
{
public:
    static int GAP;
    ComponentDecorator(Component* component);
    virtual ~ComponentDecorator();
    void draw(IGraphics* graphics);
    string getDescription();
    Component* getMindMap();
    void addChild(Component* component);
    void addSibling(Component* component, Component* insertPosition);
    void addParent(Component* component);
    bool isAncientOf(Component* component);
    void accept(ComponentVisitor* componentVisitor);
    void setDescription(string description);
    string getName();
    Component* getParent();
    void setParent(Component* parent);
    Component* findNode(int id);
    list<Component*>& getNodeList();
    Component* getComponent();

protected:
    Component* _component;
};