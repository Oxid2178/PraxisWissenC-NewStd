#include "stdafx.h"
#include "CustomerImpl.h"


CustomerImpl::CustomerImpl()
{
}


CustomerImpl::~CustomerImpl()
{
}

void CustomerImpl::setAccount(IAccountPtr account)
{
	this->customerAccount = account;
	std::cout << "The customer is set with his account and the account name is: " << this->customerAccount->getAccountName() << '\n';
}

std::string CustomerImpl::getCustomerName() const
{
	return this->customerName;
}