#pragma once

#include "IObserver.h"

class IsEqualTo
{
private:
	IObserverPtr observer;

public:
	explicit IsEqualTo(const IObserverPtr& observer)
		: observer{ observer } {}
	
	bool operator()(const IObserverPtr& observerToCompare)
	{
		return observerToCompare->getId() == observer->getId();
	}
};

