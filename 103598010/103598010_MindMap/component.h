#pragma once
#include <string>
#include "component_visitor.h"
#include <list>

using namespace std;

class ComponentVisitor;

class Component
{
public:
    Component(int id);
    virtual ~Component();
    int getId();
    void setId(int id);
    string getDescription();
    void setDescription(string description);
    string getName();
    virtual Component* getMindMap() = 0;
    Component* getParent();
    void setParent(Component* parent);
    Component* findNode(int id);
    list<Component*>& getNodeList();
    virtual void addChild(Component* component) = 0;
    virtual void addSibling(Component* component, Component* insertPosition) = 0;
    virtual void addParent(Component* component) = 0;
    virtual bool isAncientOf(Component* component) = 0;
    virtual Component* clone() = 0;
    virtual string getTypeName() = 0;
    virtual void accept(ComponentVisitor* componentVisitor) = 0;
protected:
    list<Component*> _children;
    Component* _parent;
private:
    int _id;
    string _description;
};

