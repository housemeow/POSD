#include "stdafx.h"
#include "text_ui_display_visitor.h"


TextUIDisplayVisitor::TextUIDisplayVisitor()
{
}


TextUIDisplayVisitor::~TextUIDisplayVisitor()
{
}

void TextUIDisplayVisitor::visit(Node* node)
{
    visit((Component*)node);
}

void TextUIDisplayVisitor::visit(Root* root)
{
    visit((Component*)root);
}

void TextUIDisplayVisitor::visit(Component* component)
{
    stringstream stringStream;
    getMindMapString(component, stringStream, false);
    string displayMindMapString = "The mind map " + component->getDescription() + " is displayed as follows:\n";
    displayMindMapString += stringStream.str();
    cout << displayMindMapString;
}

//產出MindMapString的遞迴函數
void TextUIDisplayVisitor::getMindMapString(Component* component, stringstream& stringStream, bool needVerticleLine)
{
    if (component) {
        stringStream << "＋－" << component->getName() << endl;
        stringstream tempStringstream;
        for (ComponentIterator iterator = component->getNodeList().begin(), end = component->getNodeList().end(); iterator != end;) {
            Component* child = *iterator;
            ++iterator;
            getMindMapString(child, tempStringstream, component->getNodeList().size() > 1 && iterator != end);
        }
        bool first = true;
        while (!tempStringstream.eof()) {
            string line;
            getline(tempStringstream, line);
            if (line.size() != 0) {
                if (needVerticleLine) {
                    stringStream << "｜　" << line << endl;
                } else {
                    stringStream << "　　" << line << endl;
                }
            }
            first = false;
        }
    }
}

