#include "stapel_test.h"
#include "gmock/gmock.h"
TEST_F (stapel_test, is_empty__empty_stack__returns_true)
{
	EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(stapel_test, is_empty__not_empty_stack__returns_true)
{
	object_under_test.push(1);
	EXPECT_FALSE(object_under_test.is_empty());
}