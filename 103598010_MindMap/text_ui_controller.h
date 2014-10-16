#pragma once
#include "mind_map_model.h"

class TextUIController
{
public:
    TextUIController(MindMapModel* mindMapModel);
    ~TextUIController();
    void run();
private:
    MindMapModel* _mindMapModel;
};