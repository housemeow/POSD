#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "triangle_decorator.h"
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

class TriangleDecoratorTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};


TEST_F(TriangleDecoratorTest, testTriangleDecorator)
{
    Node node(1);
    TriangleDecorator triangleDecorator(&node);
    triangleDecorator.setX(0);
    ASSERT_EQ(triangleDecorator.getX(), 0);
    triangleDecorator.setY(0);
    ASSERT_EQ(triangleDecorator.getY(), 0);
    ASSERT_EQ(triangleDecorator.getWidth(), node.getWidth() + ComponentDecorator::PADDING * 4);
    ASSERT_EQ(triangleDecorator.getHeight(), node.getHeight() + ComponentDecorator::PADDING * 2);
    MockGraphics mockGraphics;
    try {
        triangleDecorator.draw(&mockGraphics);
        FAIL();
    } catch (string str) {
        SUCCEED();
    }
    ASSERT_EQ(triangleDecorator.getTypeName(), TriangleDecorator::NAME);
}