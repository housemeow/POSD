#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "i_graphics.h"


class MockGraphics : public IGraphics
{
public:
    void drawText(string text, int x, int y, int width, int height)
    {
        throw string("drawText");
    }
    void drawRectangle(int x1, int y1, int x2, int y2)
    {
        throw string("drawRectangle");
    }
    void drawEllipse(int x1, int y1, int x2, int y2)
    {
        throw string("drawEllipse");
    }
    void drawTriangle(int x1, int y1, int x2, int y2)
    {
        throw string("drawTriangle");
    }
};

class IGraphicsTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};


TEST_F(IGraphicsTest, resetCurrentId)
{
    MockGraphics mockGraphics;
    try {
        mockGraphics.drawEllipse(0, 0, 0, 0);
    } catch (string str) {
        ASSERT_EQ("drawEllipse", str);
    }
    try {
        mockGraphics.drawRectangle(0, 0, 0, 0);
    } catch (string str) {
        ASSERT_EQ("drawRectangle", str);
    }
    try {
        mockGraphics.drawTriangle(0, 0, 0, 0);
    } catch (string str) {
        ASSERT_EQ("drawTriangle", str);
    }
    try {
        mockGraphics.drawText("", 0, 0, 0, 0);
    } catch (string str) {
        ASSERT_EQ("drawText", str);
    }
}