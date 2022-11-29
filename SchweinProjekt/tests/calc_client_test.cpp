#include "calc_client_test.h"

TEST_F(calc_client_test, demo)
{
	
	// Arrange
	// Record
	ON_CALL(calculatorMock, add(_, _)).WillByDefault(Return(4711.0)); 
	


	// REPLAY
	object_under_test.go();

	
}