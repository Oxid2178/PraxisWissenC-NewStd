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
		auto iter = std::find_if(begin(observers), 
                                 end(observers), 
                                 IsEqualTo(observerToAdd));

		if (iter == end(observers))
		{
			observers.push_back(observerToAdd);
            std::cout << "Observer " << observerToAdd->getId() << " added\n";
		}
	}

	void removeObserver(IObserverPtr& observerToRemove)
	{
		observers.erase(std::remove_if(begin(observers), 
                                       end(observers), 
                                       IsEqualTo(observerToRemove)), 
                                       end(observers));
        std::cout << "Observer " << observerToRemove->getId() << " removed\n";
	}

protected:
	void notifyAllObserver() const
	{
		for (const auto& observer : observers)
		{
			observer->update();
            std::cout << "Observer " << observer->getId() << " updated\n";
		}
	}
};

