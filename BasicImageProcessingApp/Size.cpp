#include "Size.h"

Size::Size()
{
	this->m_width = 0;
	this->m_height = 0;
}

Size::Size(unsigned int w, unsigned int h)
{
	this->m_width = w;
	this->m_height = h;
}

bool operator==(const Size& S1, const Size& S2)
{
	if (S1.m_height == S2.m_height && S1.m_width == S2.m_width)
		return true;
	return false;
}

bool operator!=(const Size& S1, const Size& S2)
{
	if (S1.m_height != S2.m_height || S1.m_width != S2.m_width)
		return true;
	return false;
}
