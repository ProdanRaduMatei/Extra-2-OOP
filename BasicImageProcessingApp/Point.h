#pragma once
#include <iostream>

class Point
{
public:
	Point();
	Point(unsigned int x, unsigned int y);

	unsigned int getX() { return x; }
	unsigned int getY() { return y; }

	friend std::ostream& operator<<(std::ostream& os, const Point& P);
	friend std::istream& operator>>(std::istream& os, Point& P);

private:
	unsigned int x;
	unsigned int y;
};

