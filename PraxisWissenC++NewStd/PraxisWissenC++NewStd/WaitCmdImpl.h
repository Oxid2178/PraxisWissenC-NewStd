#pragma once
#include "ICommand.h"
#include <chrono>
#include <thread>

class WaitCmdImpl : public ICommand
{
private:
	unsigned int durationInMilliseconds{1000};

public:
	explicit WaitCmdImpl(const unsigned int durationInMilliseconds)
		noexcept : durationInMilliseconds{ durationInMilliseconds } {};

	virtual void execute() override
	{
		std::chrono::milliseconds dur(durationInMilliseconds);
		std::this_thread::sleep_for(dur);
	}
};

