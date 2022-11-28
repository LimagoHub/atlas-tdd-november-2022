#pragma once
#include <ostream>
#include <string>
#include <stdexcept>
#include <boost/functional/hash.hpp>

class schwein
{
	std::string name;
	int gewicht;

	void set_gewicht(const int gewicht)
	{
		this->gewicht = gewicht;
	}

public:
	schwein(const std::string& name = "nobody")
		: name(name), gewicht(10)
	{
	}


	void set_name(const std::string& name)
	{
		if (name == "Elsa")
			throw std::invalid_argument("Name nicht erlaubt");
		
		this->name = name;
	}


	void fuettern()
	{
		set_gewicht(get_gewicht() + 1);
	}


	// Generated
	[[nodiscard]] std::string get_name() const
	{
		return name;
	}
	
	[[nodiscard]] int get_gewicht() const
	{
		return gewicht;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const schwein& obj)
	{
		return os
			<< "name: " << obj.name
			<< " gewicht: " << obj.gewicht;
	}

	friend std::size_t hash_value(const schwein& obj)
	{
		std::size_t seed = 0x1C0E9199;
		boost::hash_combine(seed, obj.name);
		boost::hash_combine(seed, obj.gewicht);
		return seed;
	}


	friend bool operator==(const schwein& lhs, const schwein& rhs)
	{
		return lhs.name == rhs.name
			&& lhs.gewicht == rhs.gewicht;
	}

	friend bool operator!=(const schwein& lhs, const schwein& rhs)
	{
		return !(lhs == rhs);
	}
};
