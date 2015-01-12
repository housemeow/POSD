#include "stdafx.h"
#include "save_visitor.h"

SaveVisitor::SaveVisitor(string fileName)
{
    _fileName = fileName;
}

SaveVisitor::~SaveVisitor()
{
}


void SaveVisitor::visit(Node* node)
{
    visit((Component*)node);
}

void SaveVisitor::visit(Root* root)
{
    visit((Component*)root);
}

void SaveVisitor::visit(Component* component)
{
    ofstream file(_fileName, ofstream::out);
    if (!file) {
        throw exception("Path is invalid!!");
    }
    ComponentFactory componentFactory;
    Component* saveMindMap = component->clone();// componentFactory.copyMindMap(component);
    int newId = 0;
    int currentId = componentFactory.getCurrentId();
    for (int id = 0; id < currentId; id++) {
        Component* component = saveMindMap->findNode(id);
        if (component) {
            component->setId(newId++);
        }
    }
    for (int id = 0; id < currentId; id++) {
        Component* component = saveMindMap->findNode(id);
        if (component) {
            file << id << " \"" << component->getDescription() << "\"";
            for (ComponentIterator iterator = component->getNodeList().begin(), end = component->getNodeList().end(); iterator != end; ++iterator) {
                Component* child = *iterator;
                file << " " << child->getId();
            }
            file << "," << component->getDecoratorName();
            file << endl;
        }
    }
    delete saveMindMap;
    file.close();
}