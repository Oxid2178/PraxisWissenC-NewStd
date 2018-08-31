#pragma once
#include "IUndoableCommand.h"
#include "DrawingProcessor.h"
#include "Point.h"

class DrawCircleCmdImpl : public IUndoableCommand
{
private:
	DrawingProcessor& receiver;
	const Point centerPoint;
	const double radius;

public:
	DrawCircleCmdImpl(DrawingProcessor& receiver, const Point& centerPoint, const double radius) noexcept
		: receiver{ receiver }, centerPoint{ centerPoint }, radius{ radius } {}

	virtual void execute() override
	{
		receiver.drawCircle(centerPoint, radius);
	}

	virtual void undo() override
	{
		receiver.eraseCircle(centerPoint, radius);
	}
};