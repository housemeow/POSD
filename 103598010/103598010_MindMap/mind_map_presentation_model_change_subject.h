#pragma once
#include "mind_map_presentation_model_change_observer.h"

class MindMapPresentationModelChangeSubject
{
public:
    void setObserver(MindMapPresentationModelChangeObserver* observer)
    {
        _observer = observer;
    }

    void updateUIState()
    {
        if (_observer) {
            _observer->updateUIState();
        }
    }

    void refreshUI()
    {
        if (_observer) {
            _observer->refreshUI();
        }
    }

    void triggerDoubleClick()
    {
        if (_observer) {
            _observer->doubleClick();
        }
    }
private:
    MindMapPresentationModelChangeObserver* _observer;
};

