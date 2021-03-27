#pragma once
class Point
{
public:
	Point();
	Point(unsigned int x, unsigned int y);

	unsigned int getX() { return x; }
	unsigned int getY() { return y; }

private:
	unsigned int x;
	unsigned int y;
};

