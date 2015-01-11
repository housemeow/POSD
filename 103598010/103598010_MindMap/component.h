#pragma once
#include <string>
#include "component_visitor.h"
#include <list>
#include <vector>
#include "i_graphics.h"

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
    virtual void setDescription(string description);
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
    virtual void draw(IGraphics* graphics);
    string getBreakLineString() const;
    string getConcatenationString(vector<string> strings) const;
    virtual int getWidth();
    virtual int getHeight();
    int getLineCount(string str) const;
    virtual int getX();
    virtual void setX(int x);
    virtual int getY();
    virtual void setY(int y);
    static const int MAX_WIDTH_PIXEL;
    static const int CHARARATER_WIDTH_PIXEL;
    static const int MAX_HEIGHT_PIXEL;
    static const int LINE_HEIGHT_PIXEL;
    static const int MAX_WIDTH_CHARACTER;
    static const int MAX_LINE;
    static const int PADDING;
protected:
    Component() {}
    list<Component*> _children;
    Component* _parent;
private:
    int _id;
    string _description;
    int _x;
    int _y;
};