#pragma once

#include "Lebewesen.h"

class Katze : public Lebewesen
{
public:
	Katze(float gewicht, float groesse);
	virtual ~Katze();
	void spielen();
	void essen();
};

