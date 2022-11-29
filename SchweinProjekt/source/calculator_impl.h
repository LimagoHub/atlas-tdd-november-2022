#pragma once

#include "calculator.h"

class calculator_impl :public calculator
{

	double x;

public:
	calculator_impl()
		: x(10)
	{
	}

	double add(double a, double b) override
	{
		return a + b + x;
	}
	double sub(double a, double b) override
	{
		return a - b;
	}
};