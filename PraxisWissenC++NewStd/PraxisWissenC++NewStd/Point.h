#pragma once
class Point
{
public:
	std::vector<unsigned int> xyCoord{ 3, 6 };
	unsigned int xCoord{ 3 };
	unsigned int yCoord{ 6 };
};

using PointPtr = std::shared_ptr<Point>;