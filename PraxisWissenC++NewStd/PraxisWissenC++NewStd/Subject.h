#pragma once

#include "IObserver.h"
#include "IsEqualTo.h"

class Subject
{
private:
	std::vector<IObserverPtr> observers;

public:
	void addObserver(IObserverPtr& observerToAdd)
	{
		auto iter = std::find_if(begin(observers), end(observers),
			IsEqualTo(observerToAdd));
		if (iter == end(observers))
		{
			observers.push_back(observerToAdd);
		}
	}

	void removeObserver(IObserverPtr& observerToRemove)
	{
		observers.erase(std::remove_if(begin(observers), end(observers),
			IsEqualTo(observerToRemove)), end(observers));
	}

protected:
	void notifyAllObserver() const
	{
		for (const auto& observer : observers)
		{
			observer->update();
		}
	}
};

