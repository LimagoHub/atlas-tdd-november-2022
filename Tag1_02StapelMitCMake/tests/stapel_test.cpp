#include "stapel_test.h"

TEST_F(stapel_test, is_empty__empty_stack__returns_true)
{
	// Arrange

	// Action
	bool ergebnis = object_under_test.is_empty();

	// Assertion

	EXPECT_TRUE(ergebnis);
}

TEST_F(stapel_test, is_empty__not_empty_stack__returns_false)
{
	// Arrange
	object_under_test.push(1);

	// Action
	bool ergebnis = object_under_test.is_empty();

	// Assertion

	EXPECT_FALSE(ergebnis);
}

TEST_F(stapel_test, push__value_saved_in_stack__xx)
{

	object_under_test.push(1);
	
	// Arrange
	


	// Action + Assertion
	EXPECT_EQ(object_under_test.pop(),1);

}


TEST_F(stapel_test, push__fill_up_to_limit__no_exception_is_thrown)
{
	// Arrange
	for (int i = 0; i < 9; ++i)
	{
		object_under_test.push(1);
	}
	

	// Action + Assertion
	EXPECT_NO_THROW(object_under_test.push(1));
	
}

TEST_F(stapel_test, push__overflow__stapel_exception_is_thrown)
{
	// Arrange
	for (int i = 0; i < 10; ++i)
	{
		object_under_test.push(1);
	}


	// Action + Assertion
	// EXPECT_THROW(object_under_test.push(1),stapel_exception);
	try
	{
		object_under_test.push(1);
		FAIL() << "Exception wurde erwartet";
	} catch(const stapel_exception &ex)
	{
		EXPECT_STREQ("Overflow", ex.what());
	}

}
