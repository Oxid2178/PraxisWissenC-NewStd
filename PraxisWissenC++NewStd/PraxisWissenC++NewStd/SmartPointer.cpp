#include "stdafx.h"
#include "SmartPointer.h"


SmartPointer::SmartPointer()
{
}


SmartPointer::~SmartPointer()
{
}

void SmartPointer::doSomethingWithNoOwnedResource(const std::weak_ptr<Ressource> &weakResource)
{
	if (!weakResource.expired())
	{
		std::shared_ptr<Ressource> sharedRessource = weakResource.lock();
		sharedRessource->hi();
	}
}
