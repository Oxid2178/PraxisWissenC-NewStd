#include "stdafx.h"
#include "Hund.h"

Hund::Hund()
{
}

Hund::Hund(float gewicht, float groesse)
{
	__super::setGewicht(gewicht);
	__super::setGroesse(groesse);
}

Hund::~Hund()
{
	std::cout << "~Hund zerstoert..." << '\n';
}

void Hund::spielen()
{
	setGewicht(-0.5);
}

void Hund::essen()
{
	setGewicht(1.0);
}
