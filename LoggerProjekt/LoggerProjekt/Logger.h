#pragma once
#include <iostream>
#include <string>
#include "Appender.h"



class Logger
{
	Appender& appender_;

public:
	Logger(Appender& appender)
		: appender_(appender)
	{
	}

	void log(std::string message)
	{
		const std::string prefix = "Prefix: "; // soll berechnet sein

		appender_.write(prefix + message);
	}
};

