#pragma once
#include "mind_map_model.h"
#include "component.h"
#include <sstream>

class TextUIView
{
public:
    TextUIView(ostream& ostream);
    ~TextUIView();
    void printMenu();
    void printMindMap(Component* component);
    void printInputNotify();
    void printCreateMindMapMessage();
    void printMindMapNotExist();
    void printEnterNodeIDMessage();
    void printEnterEditNodeIDMessage();
    void printInsertNewNodeMenu();
    void printEnterNodeNameMessage();
    void printLine(string message);
    void printException(exception exception);
    void printWrongInsertCommandMessage();
    void printWrongMenuInstruction();
    void printSaveMindMapSuccess();
    void printEnterFilePath();
    void printNodeIsNotExist();
    void printEditMenu();
    void printCommandNotFound();
    void printEnterDescription();
    void printEnterParentID();
    void printParentCannotSelectItself();
    void printCannotDeleteRoot();
    void printRootCannotChangeParent();
private:
    ostream& cout;
};