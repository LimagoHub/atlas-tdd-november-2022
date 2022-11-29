#include "calc_client_test.h"

TEST_F(calc_client_test, demo)
{
	//InSequence s;
	// Arrange
	// Record

	double parameter_to_capture;
	
	/*ON_CALL(calculatorMock, sub(_, _)).WillByDefault(Return(13.0));
	ON_CALL(calculatorMock, sub(10.0, 7.0)).WillByDefault(Return(2.0));
	ON_CALL(calculatorMock, sub(3.0, 5.0)).WillByDefault(Return(20.0));
	*/
	
	//EXPECT_CALL(calculatorMock, add(_,4.0)).WillOnce(DoAll(SaveArg<0>(&parameter_to_capture), Return(47.0)));

	EXPECT_CALL(calculatorMock, add(_, _)).WillOnce([](double a, double b)
	{
		
		return 0.0;
	});
	
	//EXPECT_CALL(calculatorMock, add(3.0, 4.0)).WillOnce(Return(4711.0));

	// REPLAY
	object_under_test.go();

	
}