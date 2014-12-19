#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "component.h"
#include "node.h"
#include "root.h"

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