#pragma once
#include "Mockpersonen_repository.h"
#include "Mockblacklist_service.h"
#include "../source/persistence/person.h"
#include "../source/services/personen_service_impl.h"
#include "../source/services/personen_service_exception.h"
using namespace testing;
class personen_service_impl_test: public Test
{
protected:
	person valid_person{ "Jane","Doe" };
	Mockpersonen_repository repoMock;
	Mockblacklist_service blacklistMock;
	personen_service_impl object_under_test{ repoMock, blacklistMock };


	
};