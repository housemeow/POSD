#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "mind_map_presentation_model_change_observer.h"
#include "mind_map_presentation_model_change_subject.h"


class MockSubject : public MindMapPresentationModelChangeSubject
{
};

class MockObserver : public MindMapPresentationModelChangeObserver
{
public:
    MockObserver()
    {
        _isCalledUpdateUIState = false;
        _isCalledRefreshUI = false;
        _isCalledDoubleClick = false;
    }

    void updateUIState()
    {
        _isCalledUpdateUIState = true;
    }

    void refreshUI()
    {
        _isCalledRefreshUI = true;
    }

    void doubleClick()
    {
        _isCalledDoubleClick = true;
    }

    bool _isCalledUpdateUIState;
    bool _isCalledRefreshUI;
    bool _isCalledDoubleClick;
};

class ObserverTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        subject = new MockSubject();
        observer = new MockObserver();
        subject->setObserver(observer);
    }

    virtual void TearDown()
    {
    }

    MindMapPresentationModelChangeSubject* subject;
    MockObserver* observer;
};

TEST_F(ObserverTest, testUpdateUIState)
{
    subject->updateUIState();
    ASSERT_TRUE(observer->_isCalledUpdateUIState);
}

TEST_F(ObserverTest, testRefreshUI)
{
    subject->refreshUI();
    ASSERT_TRUE(observer->_isCalledRefreshUI);
}

TEST_F(ObserverTest, testDoubleClick)
{
    subject->triggerDoubleClick();
    ASSERT_TRUE(observer->_isCalledDoubleClick);
}
