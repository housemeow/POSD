#include "stdafx.h"
#include <limits.h>
#include "gtest/gtest.h"

class accountTest : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        // note: _balance is a private member of account
    }
    // virtual void TearDown() {}
};

TEST_F(accountTest, withdraw)
{
    ASSERT_TRUE(true);
    ASSERT_EQ(1, 1);
    ASSERT_FALSE(true);
}