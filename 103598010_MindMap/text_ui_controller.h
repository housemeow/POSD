#pragma once
#include "mind_map_model.h"

class TextUIController
{
public:
    TextUIController(MindMapModel* mindMapModel, ostream& ostream, istream& istream);
    ~TextUIController();
    bool performUI();
    void run();
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
    map<int, bool(TextUIController::*)()> _instructionMap;
};