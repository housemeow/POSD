#pragma once
#include "mind_map_model.h"
#include "component.h"
#include <sstream>

class TextUIView
{
public:
    TextUIView();
    ~TextUIView();
    void printMenu();
    void printMindMap(Component* component);
    void getMindMapString(Component* component, stringstream& stringStream, bool needVerticleLine);
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
    void printEnterParent();
    void printParentCannotSelectItself();
};