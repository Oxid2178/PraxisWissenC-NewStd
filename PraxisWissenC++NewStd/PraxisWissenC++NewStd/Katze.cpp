#include "stdafx.h"
#include "Katze.h"


Katze::Katze(float gewicht, float groesse)
{
	setGewicht(gewicht);
	setGroesse(groesse);
}

Katze::~Katze()
{
	std::cout << "~Katze zerstoert..." << '\n';
}

void Katze::spielen()
{
	setGewicht(-0.2f);
}

void Katze::essen()
{
	setGewicht(0.5f);
}