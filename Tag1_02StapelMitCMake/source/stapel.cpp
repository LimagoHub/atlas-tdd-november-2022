#include "stapel.h"

void stapel::push(int value)
{
	if (is_full()) {
		throw stapel_exception{ "Overflow" };
	}
	feld[index++] = value;

}

int stapel::pop()
{
	if (is_empty()) {
		throw stapel_exception{ "Underflow" };
	}
	return feld[--index];

}

bool stapel::is_empty() const noexcept
{
	return index <= 0;
}
bool stapel::is_full() const noexcept
{
	return index >= 10;
}