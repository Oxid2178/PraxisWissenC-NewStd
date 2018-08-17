#include "stdafx.h"
#include "CustomerImpl.h"


CustomerImpl::CustomerImpl()
{
}


CustomerImpl::~CustomerImpl()
{
}

void CustomerImpl::setAccount(AccountPtr account)
{
	this->customerAccount = account;
	std::cout << "The customer is set with his account" << '\n';
}

std::string CustomerImpl::getCustomerName() const
{
	return this->customerName;
}