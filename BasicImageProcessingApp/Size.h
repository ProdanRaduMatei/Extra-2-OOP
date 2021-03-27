#pragma once
//#include "Image.h"
#include <iostream>

class Size// : public Image
{
public:
	Size();
	Size(unsigned int w, unsigned int h);

	unsigned int getWidth() { return m_width; }
	unsigned int getHeight() { return m_height; }

	friend bool operator==(const Size& S1, const Size& S2);
	friend bool operator!=(const Size& S1, const Size& S2);

private:
	unsigned int m_width;
	unsigned int m_height;
};
