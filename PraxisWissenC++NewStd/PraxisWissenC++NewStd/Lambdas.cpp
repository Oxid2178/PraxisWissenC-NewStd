#include "stdafx.h"
#include "Lambdas.h"


Lambdas::Lambdas()
{
}

Lambdas::~Lambdas()
{
}

int Lambdas::add(int a, int b)
{
	return a + b;
}

void Lambdas::doSomething()
{
	func = [&]{name.append(", Anthony");};
	//func = [&]{name +=", Hopkins"; };

	std::cout << name << std::endl;
}

void Lambdas::printName()
{
	std::cout << name << std::endl;
}


