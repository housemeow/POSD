#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "node.h"
#include "root.h"

class NodeTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _node = new Node(0);
    }

    virtual void TearDown()
    {
        delete _node;
    }

    Node* _node;
};


TEST_F(NodeTest, testConstructor)
{
    ASSERT_EQ("", _node->getDescription());
    ASSERT_EQ(0, _node->getNodeList().size());
    ASSERT_EQ(NULL, _node->getParent());
}

TEST_F(NodeTest, testTypeName)
{
    ASSERT_EQ("Node", _node->getTypeName());
}

TEST_F(NodeTest, testGetMindMap)
{
    Node* nodeParent = new Node(2);
    Root* root = new Root(1);
    _node->setParent(nodeParent);
    nodeParent->setParent(root);
    ASSERT_EQ(root, _node->getMindMap());
    ASSERT_EQ(root, nodeParent->getMindMap());
}

TEST_F(NodeTest, testAddChild)
{
    Node* nodeChild = new Node(2);
    _node->addChild(nodeChild);
    ASSERT_EQ(1, _node->getNodeList().size());
    ASSERT_EQ(_node, nodeChild->getParent());
}

TEST_F(NodeTest, testAddSibling)
{
    Node* parentNode = new Node(2);
    parentNode->addChild(_node);
    Node* siblingNode = new Node(3);
    _node->addSibling(siblingNode);
    ASSERT_EQ(2, parentNode->getNodeList().size());
    ASSERT_EQ(parentNode, siblingNode->getParent());
}

TEST_F(NodeTest, testAddParent)
{
    Node* parentNode = new Node(2);
    parentNode->addChild(_node);
    Node* newParentNode = new Node(3);
    _node->addParent(newParentNode);
    ASSERT_EQ(newParentNode, _node->getParent());
    ASSERT_EQ(parentNode, newParentNode->getParent());
}

TEST_F(NodeTest, testIsAncientOf)
{
    Node* parentNode = new Node(2);
    parentNode->addChild(_node);
    Node* newParentNode = new Node(3);
    _node->addParent(newParentNode);
    ASSERT_TRUE(parentNode->isAncientOf(_node));
    ASSERT_TRUE(newParentNode->isAncientOf(_node));
    ASSERT_FALSE(_node->isAncientOf(newParentNode));
    ASSERT_FALSE(_node->isAncientOf(parentNode));
}

TEST_F(NodeTest, testFindNode)
{
    Node* nodeChild = new Node(1);
    _node->addChild(nodeChild);
    ASSERT_EQ(nodeChild, _node->findNode(1));
    ASSERT_EQ(_node, _node->findNode(0));
    ASSERT_EQ(NULL, _node->findNode(2));
}