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