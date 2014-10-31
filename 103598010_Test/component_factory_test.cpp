#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"
#include "component_factory.h"

class ComponentFactoryTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        // note: _balance is a private member of account
    }
    // virtual void TearDown() {}

    ComponentFactory _componentFactory;
};

TEST_F(ComponentFactoryTest, withdraw)
{
    Component* component = _componentFactory.createComponent(ComponentTypeNode, 0);
    bool value = false;
    ASSERT_EQ(0, component->getId());
    ASSERT_TRUE(true);
    //ASSERT_EQ(true, value);
    ASSERT_EQ(1, 1);
}