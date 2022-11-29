#pragma once
#include <iostream>

#include "Appender.h"
class ConsolenAppender :
    public Appender
{
public:
	void write(std::string message) const override
	{
		std::cout << message << std::endl;
	}
};

