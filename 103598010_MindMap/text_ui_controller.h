#pragma once
#include "text_ui_view.h"
#include "mind_map_model.h"

class TextUIController
{
public:
    TextUIController(MindMapModel* mindMapModel, TextUIView* textUIView);
    ~TextUIController();
    void run();
private:
    MindMapModel* _mindMapModel;
    TextUIView* _textUIView;
};