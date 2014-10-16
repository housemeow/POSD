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
    void printMindMap(MindMapModel* mindMapModel);
    void getMindMapString(Component* component, stringstream& stringStream, bool needVerticleLine);
    void printInputNotify();
    void printCreateMindMapMessage();
};