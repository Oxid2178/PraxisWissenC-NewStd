#pragma once

#include "stdafx.h"
#include <set>

class Person
{
private:
	std::string name;
	std::set<std::string> bekannte;

public:
	Person(const std::string &name) : name(name)
	{
	}
	virtual ~Person() = default;

	const std::string& getName() const 
	{
		return name;
	}

	void lerntkennen(Person &p)
	{
		bool nichtvorhanden = bekannte.insert(p.getName()).second;
		if (nichtvorhanden) // falls unbekannt, auch bei p eintragen
		{
			p.lerntkennen(*this);
		}
	}

	void bekannteZeigen() const
	{
		std::cout << "Die bekannten von " << getName() << " sind:\n";
		for (auto bekannt : bekannte)
		{
			std::cout << bekannt << '\n';
		}
	}
 };

