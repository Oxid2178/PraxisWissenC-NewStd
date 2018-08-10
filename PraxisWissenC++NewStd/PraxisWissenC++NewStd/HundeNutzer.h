#pragma once

#include "IHund.h"

class HundeNutzer
{
public:
	HundeNutzer(IHund &hund);
	~HundeNutzer();

	void spieleMitHund();
	void essenMitHund();
	float gibBMI();

private:
	IHund &_hund;
};

