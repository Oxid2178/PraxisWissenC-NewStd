#include "stdafx.h"
#include "HundeNutzer.h"
#include "Lebewesen.h"

HundeNutzer::HundeNutzer(IHund &hund) : _hund(hund)
{
}

HundeNutzer::~HundeNutzer()
{
	std::cout << "~HundeNutzer zerstoert..." << '\n';
}

void HundeNutzer::spieleMitHund()
{
	_hund.spielen();
}

void HundeNutzer::essenMitHund()
{
	_hund.essen();
}

float HundeNutzer::gibBMI()
{
	return dynamic_cast<Lebewesen&>(_hund).berechneBMI();
}
