#include "stdafx.h"
#include "Customer.h"


Customer::Customer()
{
}


Customer::~Customer()
{
}

void Customer::setAccount(Account *account)
{
	this->customerAccount = account;
	std::cout << "The customer is set with his account" << '\n';
}
