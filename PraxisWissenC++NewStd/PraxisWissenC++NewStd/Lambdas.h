#pragma once

#include <functional>
#include <iostream>

class Lambdas
{
public:
	Lambdas();
	virtual ~Lambdas();

	int add(int a, int b);

	void doSomething();
	std::function<void()> func;
	std::string name{ "Williams" };
	void printName();

private:
	int a{ 0 };
	int b{ 0 };
};

