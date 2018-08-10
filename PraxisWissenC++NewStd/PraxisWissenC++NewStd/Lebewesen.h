#pragma once

class Lebewesen
{
public:
	Lebewesen();
	Lebewesen(float gewicht, float groesse);
	virtual ~Lebewesen();

	float berechneBMI();
	void setGewicht(float gewicht);
	void setGroesse(float groesse);

private:
	float mGewicht = 0;
	float mGroesse = 0;
};

