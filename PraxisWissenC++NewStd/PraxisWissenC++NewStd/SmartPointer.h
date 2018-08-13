#pragma once

#include "Ressource.h"

class SmartPointer
{
public:
	SmartPointer();
	~SmartPointer();
	void doSomethingWithNoOwnedResource(const std::weak_ptr<Ressource> &weakResource);
};

