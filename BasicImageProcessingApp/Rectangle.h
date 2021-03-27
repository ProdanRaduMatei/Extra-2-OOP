#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	unsigned int getX() { return x; }
	unsigned int getY() { return y; }
	unsigned int getWidth() { return width; }
	unsigned int getHeight() { return height; }

private:
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
};

