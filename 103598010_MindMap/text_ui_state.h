#pragma once
#include "text_ui_view.h"


class TextUIState
{
public:
    TextUIState(MindMapModel* mindMapModel);
    virtual ~TextUIState();
    virtual TextUIState* run() = 0;
protected:
    string readLineString(bool printNotify = true);
    int readInt();
    char readChar();
    TextUIView _textUIView;
    MindMapModel* _mindMapModel;
};

