#pragma once
#include "calculator.h"
// Stub Stellvertreter
class calc_client
{
	calculator &calc;
public:
	calc_client(calculator& calc)
		: calc(calc)
	{
	}

	void go()
	{
		
		std::cout << "Summe = " << calc.add(4.0, 4.0) << std::endl;
		
		
	
		
		
	}
};