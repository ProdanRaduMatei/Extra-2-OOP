#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(unsigned int x, unsigned int y)
{
	this->x = x;
	this->y = y;
}

std::ostream& operator<<(std::ostream& os, const Point& P)
{
	os << "(" << P.x << "," << P.y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point& P)
{
	is >> P.x >> P.y;
	return is;
}
