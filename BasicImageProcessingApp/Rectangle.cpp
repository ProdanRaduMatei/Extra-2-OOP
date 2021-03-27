#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->x = 0;
	this->y = 0;
	this->height = 0;
	this->width = 0;
}

Rectangle::Rectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
}
