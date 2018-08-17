#pragma once

//#include "stdafx.h"

class IOwner
{
public:
	virtual ~IOwner() = default;
	virtual std::string getCustomerName() const = 0;
};

using IOwnerPtr = std::shared_ptr<IOwner>;