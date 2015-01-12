#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "rectangle_decorator.h"
#include "node.h"

class MockGraphics : public IGraphics
{
public:
    void drawText(string text, int x, int y, int width, int height)
    {
        throw string("drawText");
    }
    void drawRectangle(int x1, int y1, int x2, int y2)
    {
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

class RectangleDecoratorTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};


TEST_F(RectangleDecoratorTest, testRectangleDecoratorTest)
{
    Node node(1);
    RectangleDecorator rectangleDecorator(&node);
    rectangleDecorator.setX(0);
    ASSERT_EQ(rectangleDecorator.getX(), 0);
    rectangleDecorator.setY(0);
    ASSERT_EQ(rectangleDecorator.getY(), 0);
    ASSERT_EQ(rectangleDecorator.getWidth(), node.getWidth() + ComponentDecorator::PADDING * 2);
    ASSERT_EQ(rectangleDecorator.getHeight(), node.getHeight() + ComponentDecorator::PADDING * 2);
    MockGraphics mockGraphics;
    try {
        rectangleDecorator.draw(&mockGraphics);
        FAIL();
    } catch (string str) {
        SUCCEED();
    }
    ASSERT_EQ(rectangleDecorator.getTypeName(), RectangleDecorator::NAME);
}