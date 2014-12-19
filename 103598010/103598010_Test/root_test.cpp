#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "node.h"
#include "root.h"

class RootTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _root = new Root(0);
    }

    virtual void TearDown()
    {
        delete _root;
    }

    Root* _root;
};


TEST_F(RootTest, testConstructor)
{
    ASSERT_EQ("", _root->getDescription());
    ASSERT_EQ(0, _root->getNodeList().size());
    ASSERT_EQ(NULL, _root->getParent());
}

TEST_F(RootTest, testTypeName)
{
    ASSERT_EQ("Root", _root->getTypeName());
}

TEST_F(RootTest, testGetMindMap)
{
    ASSERT_EQ(_root, _root->getMindMap());
}

TEST_F(RootTest, testAddChild)
{
    Node* nodeChild = new Node(2);
    _root->addChild(nodeChild);
    ASSERT_EQ(1, _root->getNodeList().size());
    ASSERT_EQ(_root, nodeChild->getParent());
}

TEST_F(RootTest, testAddSibling)
{
    Node* siblingNode = new Node(2);
    try {
        _root->addSibling(siblingNode, _root);
        FAIL();
    } catch (exception exception) {
        ASSERT_EQ("Root can't insert sibling node", string(exception.what()));
    }
}

TEST_F(RootTest, testAddParent)
{
    Node* parentNode = new Node(2);
    try {
        _root->addParent(parentNode);
        FAIL();
    } catch (exception exception) {
        ASSERT_EQ("Root can't insert parent node", string(exception.what()));
    }
}

TEST_F(RootTest, testIsAncientOf)
{
    Node* childNode = new Node(2);
    Node* childOfChildNode = new Node(3);
    _root->addChild(childNode);
    childNode->addChild(childOfChildNode);
    ASSERT_TRUE(_root->isAncientOf(childNode));
    ASSERT_TRUE(_root->isAncientOf(childOfChildNode));
    ASSERT_FALSE(childNode->isAncientOf(_root));
    ASSERT_FALSE(childOfChildNode->isAncientOf(_root));
}