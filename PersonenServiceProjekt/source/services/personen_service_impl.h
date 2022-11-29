#pragma once
#include "../persistence/person.h"
#include "../persistence/personen_repository.h"
#include "personen_service_exception.h"
#include "blacklist_service.h"
#include <random>
class personen_service_impl // :public personen_service
{
	personen_repository& repo_;
	blacklist_service& blacklist_service_;
	void validate_person(person& person_)
	{
		int iid = rand();

		person_.set_id(std::to_string(iid));
			
		if (person_.get_vorname().length() < 2)
			throw personen_service_exception{ "Vorname zu kurz" };

		if (person_.get_nachname().length() < 2)
			throw personen_service_exception{ "Nachname zu kurz" };

		if (blacklist_service_.is_blacklisted(person_))
			throw personen_service_exception{ "Antipath" };

	}

	void speichern_impl(person& person_)
	{
		validate_person(person_);
		
		repo_.save_or_update(person_);
	}


public:


	personen_service_impl(personen_repository& repo, blacklist_service& blacklist_service)
		: repo_(repo),
		  blacklist_service_(blacklist_service)
	{
	}

	/*
	*	Vorname < 2 -> PSE
	*	Nachname < 2 -> PSE
	*
	*	Attila -> PSE
	*
	*	Alle Technische Exceptions -> PSE
	*
	*	Happy Day -> person an Save Methode uebergeben
	*
	*/
	void speichern(person& person_)
	{

		try {
			speichern_impl(person_);
		} catch (const personen_service_exception )
		{
			throw ;
		} catch(...)
		{
			throw personen_service_exception{ "Fehler beim Speichern" };
		}
		
	}


	void speichern(std::string vorname, std::string nachname)
	{

		speichern(person{ vorname, nachname });

	}
};
