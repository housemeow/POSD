#pragma once
#include "text_ui_view.h"


class TextUIState
{
public:
    TextUIState(MindMapModel* mindMapModel);
    virtual ~TextUIState();
    virtual TextUIState* run() = 0;
    void setTextUIView(TextUIView* textUIView);
protected:
    string readLineString(bool printNotify = true);
    int readInt(bool printNotify = true);
    char readChar(bool printNotify = true);
    TextUIView* _textUIView;
    MindMapModel* _mindMapModel;
};

