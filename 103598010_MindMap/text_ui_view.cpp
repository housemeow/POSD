#include "stdafx.h"
#include "text_ui_view.h"
#include "mind_map_model.h"

TextUIView::TextUIView()
{
}


TextUIView::~TextUIView()
{
}

void TextUIView::printMenu()
{
    cout << "1. Create a new mind map\n";
    cout << "2. Insert a new node\n";
    cout << "3. Display mind map\n";
    cout << "4. Save mind map\n";
    cout << "5. Exit\n";
}

//輸出MindMap
void TextUIView::printMindMap(MindMapModel* mindMapModel)
{
    stringstream stringStream;
    getMindMapString(mindMapModel->getMindMap(), stringStream, false);
    string displayMindMapString = "The mind map " + mindMapModel->getMindMap()->getDescription() + " is displayed as follows:\n";
    displayMindMapString += stringStream.str();
    cout << displayMindMapString;
}

//產出MindMapString的遞迴函數
void TextUIView::getMindMapString(Component* component, stringstream& stringStream, bool needVerticleLine)
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


void TextUIView::printInputNotify()
{
    cout << ">";
}


void TextUIView::printCreateMindMapMessage()
{
    cout << "Please enter the topic:\n";
}

void TextUIView::printMindMapNotExist()
{
    cout << "Mind map is not exist\n";
}

void TextUIView::printEnterNodeIDMessage()
{
    cout << "Enter the node ID:\n";
}

void TextUIView::printInsertNewNodeMenu()
{
    cout << "a. Insert a parent node\n";
    cout << "b. Insert a child node\n";
    cout << "c. Insert a sibling node\n";
}

void TextUIView::printEnterNodeNameMessage()
{
    cout << "Enter the node name\n";
}


void TextUIView::printLine(string message)
{
    cout << message << endl;
}
void TextUIView::printWrongInsertCommandMessage()
{
    cout << "insert command is not correct!\n";
}
