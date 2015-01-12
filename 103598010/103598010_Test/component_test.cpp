#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "component.h"
#include "node.h"
#include "root.h"

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

class ComponentTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _root = new Root(1);
    }

    virtual void TearDown()
    {
    }
    Component* _root;
};

TEST_F(ComponentTest, testUpdateUIState)
{
    ASSERT_EQ(_root, _root->findNode(1));
    ASSERT_EQ(NULL, _root->findNode(0));
}

TEST_F(ComponentTest, testClone)
{
    Component* node1 = new Node(1);
    node1->setDescription("abc");
    Component* node2 = node1->clone();
    node1->addChild(node2);
    Component* node3 = node1->clone();
    ASSERT_EQ(node1->getDescription(), node2->getDescription());
    ASSERT_EQ(node1->getDescription(), node3->getDescription());
}

TEST_F(ComponentTest, testGetMindMap)
{
    Component* node = new Node(1);
    ASSERT_EQ(NULL, node->getMindMap());
}

TEST_F(ComponentTest, testCollapse)
{
    Component* node = new Node(1);
    node->setCollapse(true);
    ASSERT_TRUE(node->isCollapse());
}

TEST_F(ComponentTest, testFindNode)
{
    Component* node = new Node(1);
    ASSERT_TRUE(NULL == node->findNode(2));
}

TEST_F(ComponentTest, testDraw)
{
    Component* node = new Node(1);
    MockGraphics graphics;
    try {
        node->draw(&graphics);
        FAIL();
    } catch (string str) {
        ASSERT_EQ("drawText", str);
    }
}

TEST_F(ComponentTest, testBreakLine)
{
    Component* node = new Node(1);
    node->setDescription("hello");
    ASSERT_EQ("hello", node->getBreakLineString());
    node->setDescription("Hell Hell Hell Hell Hell Hell Hell Hell ");
    ASSERT_EQ("Hell Hell Hell Hell Hell\nHell Hell Hell", node->getBreakLineString());
}