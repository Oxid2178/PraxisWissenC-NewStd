#include "stdafx.h"
#include "AccountImpl.h"


AccountImpl::AccountImpl()
{
}


AccountImpl::~AccountImpl()
{
}

void AccountImpl::setOwner(IOwnerPtr owner)
{
	this->owner = owner;
	std::cout << "The account is set with his customer owner and customer name is: " << this->owner->getCustomerName() << '\n';
}

std::string AccountImpl::getAccountName() const
{
	return accountName;
}