#pragma once
#include "../persistence/person.h"
class blacklist_service
{
public:
	virtual bool is_blacklisted(const person& p) const = 0;
};
