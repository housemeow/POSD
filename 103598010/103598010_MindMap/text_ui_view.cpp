#include "stdafx.h"
#include "text_ui_view.h"
#include "mind_map_model.h"
#include "text_ui_display_visitor.h"

TextUIView::TextUIView(ostream& ostream): cout(ostream)
{
}


TextUIView::~TextUIView()
{
}

void TextUIView::printMenu()
{
    cout << "1. Create a new mind map\n";
    cout << "2. Insert a new node\n";
    cout << "3. Edit a node\n";
    cout << "4. Display mind map\n";
    cout << "5. Save mind map\n";
    cout << "6. Load mind map\n";
    cout << "7. Redo\n";
    cout << "8. Undo\n";
    cout << "9. Exit\n";
}

//¿é¥XMindMap
void TextUIView::printMindMap(Component* component)
{
    TextUIDisplayVisitor textUIDisplayVisitor;
    if (component) {
        component->accept(&textUIDisplayVisitor);
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
    cout << "Enter the node ID:";
}

void TextUIView::printEnterEditNodeIDMessage()
{
    cout << "Enter the edit node ID:\n";
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


void TextUIView::printException(exception exception)
{
    cout << exception.what() << endl;
}

void TextUIView::printWrongInsertCommandMessage()
{
    cout << "insert command is not correct!\n";
}

void TextUIView::printWrongMenuInstruction()
{
    cout << "menu instrution is not correct!\n";
}

void TextUIView::printSaveMindMapSuccess()
{
    cout << "Save MindMap Success\n";
}


void TextUIView::printEnterFilePath()
{
    cout << "Please input a file path:";
}

void TextUIView::printNodeIsNotExist()
{
    cout << "The node is not exist!!\n";
}

void TextUIView::printEditMenu()
{
    cout << "a. Edit the description of a node\n";
    cout << "b. Change the parent of a node\n";
    cout << "c. Delete a node\n";
}

void TextUIView::printCommandNotFound()
{
    cout << "The command is not found!!\n";
}

void TextUIView::printEnterDescription()
{
    cout << "Enter the description: ";
}

void TextUIView::printEnterParentID()
{
    cout << "Enter the parent:";
}

void TextUIView::printParentCannotSelectItself()
{
    cout << "You can'tselect itself!!\n";
}

void TextUIView::printCannotDeleteRoot()
{
    cout << "You can't delete the root.\n";
}

void TextUIView::printRootCannotChangeParent()
{
    cout << "Root can't be changed the parent.\n";
}