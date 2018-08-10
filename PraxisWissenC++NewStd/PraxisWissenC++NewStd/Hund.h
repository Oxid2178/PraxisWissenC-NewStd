#pragma once

#include "IHund.h"
#include "Lebewesen.h"

class Hund : public Lebewesen, public IHund
{
public:
	Hund();
	Hund(float gewicht, float groesse);
	virtual ~Hund();
	void spielen() override;
	void essen() override;
};

