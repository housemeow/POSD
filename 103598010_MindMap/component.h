#pragma once

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
    Component* getParent();
    void setParent(Component* parent);
    Component* findNode(int id);
    std::list<Component*>& getNodeList();
    virtual void addChild(Component* component) = 0;
    virtual void addSibling(Component* component) = 0;
    virtual void addParent(Component* component) = 0;
    virtual bool isAncientOf(Component* component) = 0;
    virtual string getTypeName() = 0;
protected:
    list<Component*> _children;
    Component* _parent;
private:
    int _id;
    string _description;
};

