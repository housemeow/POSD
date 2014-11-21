#pragma once
class MindMapPresentationModelChangeListener
{
public:
    virtual void updateUIState() = 0;
    virtual void refreshUI() = 0;
    virtual void doubleClick() = 0;
};

