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