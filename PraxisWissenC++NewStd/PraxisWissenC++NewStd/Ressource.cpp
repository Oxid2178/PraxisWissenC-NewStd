#include "stdafx.h"
#include "Ressource.h"


Ressource::Ressource(int i): id(i)
{
	std::cout << "Konstruktor Ressource()" << '\n';
}


Ressource::~Ressource()
{
	std::cout << "*********************** Ressource::Destruktor, Id=" << id << "***********************\n";
}

void Ressource::hi() const
{
	std::cout << "Hier ist Ressource::hi(), Id=" << id << '\n';
}
