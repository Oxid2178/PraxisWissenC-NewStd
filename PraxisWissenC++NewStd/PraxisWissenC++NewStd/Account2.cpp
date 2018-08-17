#include "stdafx.h"
#include "Account2.h"


Account2::Account2()
{
}


Account2::~Account2()
{
}

void Account2::setOwner(IOwnerPtr owner)
{
	this->owner = owner;
	std::cout << "The account is set with his customer owner, here the name is: " << this->owner->getCustomerName() << '\n';
}