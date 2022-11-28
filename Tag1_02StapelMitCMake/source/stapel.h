#pragma once
#include "stapel_exception.h"
class stapel
{
	int feld[10];
	int index;


public:
	stapel() : index(0)
	{
	}

	void push(int value);
	int pop();
	bool is_empty() const noexcept;
	bool is_full() const noexcept;
};



