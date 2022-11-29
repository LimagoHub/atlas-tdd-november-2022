#pragma once

#include "gtest/gtest.h"

#include "../source/clac_client.h"
#include "../source/calculator.h"
#include "Mockcalculator.h"

using namespace testing;

class calc_client_test :public Test
{
protected:
	NiceMock<Mockcalculator> calculatorMock;
	calc_client object_under_test{calculatorMock};



}; 