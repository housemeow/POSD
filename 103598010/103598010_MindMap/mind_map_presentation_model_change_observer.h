#pragma once
class MindMapPresentationModelChangeObserver
{
public:
    virtual void updateUIState() = 0;
    virtual void refreshUI() = 0;
    virtual void doubleClick() = 0;
};

