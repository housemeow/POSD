#pragma once
class TextUIState
{
public:
    TextUIState();
    virtual ~TextUIState();
    virtual TextUIState* run() = 0;
};

