#pragma once
class IObserver
{
public:
	virtual ~IObserver() = default;
	virtual int getId() = 0;
	virtual void update() = 0;
};

using IObserverPtr = std::shared_ptr<IObserver>;