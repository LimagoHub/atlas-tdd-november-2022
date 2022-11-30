#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test, speichern__vorname_zu_kurz__throws_personen_service_exception)
{
	// Arrange
	person invalid_person{ "J","Doe" };

	// Act
	try
	{
		object_under_test.speichern(invalid_person);
		FAIL() << "Exception expected";
		
	} catch (const personen_service_exception & ex)
	{
		// Assertion
		EXPECT_STREQ("Vorname zu kurz", ex.what());
		
	}
}

TEST_F(personen_service_impl_test, speichern__nachname_zu_kurz__throws_personen_service_exception)
{
	try {
		person not_valid_person{ "John", "D" };
		object_under_test.speichern(not_valid_person);
		FAIL() << "unerwartet keine Exception";
	}
	catch (personen_service_exception& ex)
	{
		EXPECT_STREQ("Nachname zu kurz", ex.what());
	}
}

TEST_F(personen_service_impl_test, speichern__Unerwuenschte_Person__throws_personen_service_exception)
{
	try {

		EXPECT_CALL(blacklistMock, is_blacklisted).WillOnce(Return(true));
		object_under_test.speichern(valid_person);
		FAIL() << "unerwartet keine Exception";
	}
	catch (personen_service_exception& ex)
	{
		EXPECT_STREQ("Antipath", ex.what());
	}
}
TEST_F(personen_service_impl_test, speichern__exception_in_underlying_service__throws_personen_service_exception)
{
	try {
		EXPECT_CALL(blacklistMock, is_blacklisted).WillOnce(Return(false));
		EXPECT_CALL(repoMock, save_or_update(_)).WillOnce(Throw(std::out_of_range{ "Dummy" }));
		object_under_test.speichern(valid_person);
		FAIL() << "unerwartet keine Exception";
	}
	catch (personen_service_exception& ex)
	{
		EXPECT_STREQ("Fehler beim Speichern", ex.what());
	}
}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo)
{

	InSequence s;
	person captured_person;
	EXPECT_CALL(blacklistMock, is_blacklisted).WillOnce(Return(false));
	EXPECT_CALL(repoMock, save_or_update).WillOnce(DoAll(SaveArg<0>(&captured_person)));
	
	object_under_test.speichern(valid_person);

	
	EXPECT_THAT( captured_person.get_vorname(), AnyOf(StartsWith("J"), StartsWith("M")));
	EXPECT_EQ("Doe", captured_person.get_nachname());
		
}