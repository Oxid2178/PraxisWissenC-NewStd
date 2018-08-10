#include "stdafx.h"
#include "Lebewesen.h"

Lebewesen::Lebewesen()
{
}

Lebewesen::Lebewesen(float gewicht, float groesse) : mGewicht(gewicht), mGroesse(groesse)
{
}

Lebewesen::~Lebewesen()
{
	std::cout << "~Lebewesen zerstoert..." << '\n';
}

float Lebewesen::berechneBMI()
{
	return mGewicht / (mGroesse * mGroesse);
}

void Lebewesen::setGewicht(float gewicht)
{
	mGewicht += gewicht;
}
	
void Lebewesen::setGroesse(float groesse) 
{
	mGroesse += groesse;
}
