#include "stdafx.h"
#include "Account.h"


Account::Account()
{
}


Account::~Account()
{
}

void Account::setOwner(Customer *customer)
{
	this->owner = customer;
	std::cout << "The account is set with his owner customer" << '\n';
}