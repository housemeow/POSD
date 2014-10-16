#pragma once
#include "text_ui_view.h"


class TextUIState
{
public:
    TextUIState(MindMapModel* mindMapModel);
    virtual ~TextUIState();
    virtual TextUIState* run() = 0;
protected:
    string readLineString();
    int readInt();

    TextUIView _textUIView;
    MindMapModel* _mindMapModel;
};

