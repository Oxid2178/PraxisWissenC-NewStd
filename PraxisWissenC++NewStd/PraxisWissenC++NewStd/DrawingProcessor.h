#pragma once
#include "Point.h"

class DrawingProcessor
{
public:
	void drawCircle(const Point& centerPoint, const double radius)
	{
		std::cout << "Draw a circle..." << "\n";
	}

	void eraseCircle(const Point& centerPoint, const double radius)
	{
		std::cout << "Erase a circle..." << "\n";
	}
};

