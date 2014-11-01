#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "text_ui_controller.h"

class TextUIControllerTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};


TEST_F(TextUIControllerTest, testRun)
{
    MindMapModel mindMapModel;
    TextUIView textUIView(cout);
    istringstream istringstream("9\n");
    TextUIController textUIController(&mindMapModel, &textUIView);
    textUIController.setIStream(&istringstream);
    textUIController.run();
}
