#pragma once
#include "mind_map_model.h"

class TextUI
{
public:
    TextUI(MindMapModel* mindMapModel, ostream& ostream, istream& istream);
    ~TextUI();
    bool performUI();
private:
    ostream& _ostream;
    istream& _istream;

    bool createMindMap();
    bool insertNewNode();
    bool displayMindMap();
    bool saveMindMap();
    bool exit();
    MindMapModel* _mindMapModel;
    string readLineString(string message);
    int readInt(string message);
    char readChar(string message);
    map<int, bool(TextUI::*)()> _instructionMap;
};