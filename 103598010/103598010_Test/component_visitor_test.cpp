#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "decorator_factory.h"
#include "rectangle_decorator.h"
#include "node.h"
#include "component_visitor.h"
#include "root.h"

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
    Node node(1);
    Root root(1);
    RectangleDecorator rectangleDecorator(&node);
    ComponentVisitor visitor;
    node.accept(&visitor);
    root.accept(&visitor);
    rectangleDecorator.accept(&visitor);
}