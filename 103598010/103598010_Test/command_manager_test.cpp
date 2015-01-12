#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "command_manager.h"
#include "component.h"
#include "root.h"
#include "edit_description_command.h"

class CommandManagerTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
    CommandManager _manager;
};


TEST_F(CommandManagerTest, resetCurrentId)
{
    Component* component = new Root(1);
    EditDescriptionCommand command(component, "new");
    _manager.clear();
    try {
        _manager.undo();
        FAIL();
    } catch (exception) {
        SUCCEED();
    }
    try {
        _manager.redo();
        FAIL();
    } catch (exception) {
        SUCCEED();
    }
}

TEST_F(CommandManagerTest, testRedo)
{
    Component* component = new Root(1);
    EditDescriptionCommand command(component, "new");
    _manager.execute(&command);
    _manager.undo();
    _manager.clearRedo();
    ASSERT_EQ(0, _manager.getRedoCount());
    ASSERT_EQ(0, _manager.getUndoCount());
}