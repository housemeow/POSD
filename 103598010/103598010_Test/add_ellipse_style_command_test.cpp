#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "command_manager.h"
#include "component.h"
#include "node.h"
#include "root.h"
#include "add_ellipse_style_command.h"

class AddEllipseStyleCommandTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        _root = new Root(0);
        _node = new Node(1);
        _root->addChild(_node);
    }

    virtual void TearDown()
    {
    }
    Node* _node;
    Root* _root;
};


TEST_F(AddEllipseStyleCommandTest, resetCurrentId)
{
    AddEllipseStyleCommand command(_node);
    command.execute();
    ASSERT_NE(*(_root->getNodeList().begin()), _node);
    command.unexecute();
    ASSERT_EQ(*(_root->getNodeList().begin()), _node);
}