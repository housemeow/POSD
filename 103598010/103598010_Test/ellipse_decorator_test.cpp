#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "ellipse_decorator.h"
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

class EllipseDecoratorTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};


TEST_F(EllipseDecoratorTest, testEllipseDecoratorTest)
{
    Node node(1);
    EllipseDecorator ellipseDecorator(&node);
    ellipseDecorator.setX(0);
    ASSERT_EQ(ellipseDecorator.getX(), 0);
    ellipseDecorator.setY(0);
    ASSERT_EQ(ellipseDecorator.getY(), 0);
    ASSERT_EQ(ellipseDecorator.getWidth(), node.getWidth() + ComponentDecorator::PADDING * 2);
    ASSERT_EQ(ellipseDecorator.getHeight(), node.getHeight() + ComponentDecorator::PADDING * 2);
    MockGraphics mockGraphics;
    try {
        ellipseDecorator.draw(&mockGraphics);
        FAIL();
    } catch (string str) {
        SUCCEED();
    }
    ASSERT_EQ(ellipseDecorator.getTypeName(), EllipseDecorator::NAME);
}