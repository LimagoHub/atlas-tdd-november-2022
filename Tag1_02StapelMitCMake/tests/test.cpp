#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {

	// Arrange
	// Act
	// Assertion
	ASSERT_EQ(1, 1); // Nachfolgende Pruefungen werden bei failed ignoriert
	EXPECT_TRUE(true);
}

