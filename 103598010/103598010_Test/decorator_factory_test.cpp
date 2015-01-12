#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "decorator_factory.h"
#include "rectangle_decorator.h"
#include "ellipse_decorator.h"
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

class DecorateFactoryTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};


TEST_F(DecorateFactoryTest, testDecorateFactory)
{
    DecoratorFactory factory;
    Node node(1);
    ASSERT_TRUE(NULL != factory.create(RectangleDecorator::NAME, &node));
    ASSERT_TRUE(NULL != factory.create(EllipseDecorator::NAME, &node));
    ASSERT_TRUE(NULL != factory.create(TriangleDecorator::NAME, &node));
    try {
        factory.create("Exception", &node);
        FAIL();
    } catch (exception exception) {
        SUCCEED();
    }
}