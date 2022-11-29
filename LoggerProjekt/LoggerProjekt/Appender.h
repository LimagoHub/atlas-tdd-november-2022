#pragma once
#include <string>

class Appender
{
public:
	virtual void write(std::string message) const = 0;
};
