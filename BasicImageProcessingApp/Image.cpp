#include "Image.h"
#include "Size.h"
#include <exception>

using namespace std;

Image::Image()
{
	this->m_width = 0;
	this->m_height = 0;
	this->m_data = new unsigned char*;
}

Image::Image(unsigned int w, unsigned int h)
{
	this->m_width = w;
	this->m_height = h;
	this->m_data = new unsigned char*;
}

Image::Image(const Image& other)
{
	if (this->m_height != other.m_height || this->m_width != other.m_width)
		throw exception();

	this->m_height = other.m_height;
	this->m_width = other.m_width;

	delete[] this->m_data;
	this->m_data = new unsigned char*;

	for (int i = 0; i < this->m_height ; i++)
		for (int j = 0; j < this->m_width; j++)
			this->m_data[i][j] = other.m_data[i][j];
}

Image::~Image()
{
	delete[] m_data;
}

Image& Image::operator=(const Image& other)
{
	if (this == &other)
		return *this;
	this->m_height = other.m_height;
	this->m_width = other.m_width;

	delete[] this->m_data;
	this->m_data = new unsigned char*;

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			this->m_data[i][j] = other.m_data[i][j];
	return *this;
}

Image Image::operator+(const Image& image)
{
	if (this->size() != image.size())
		throw exception();

	Image result;

	result.m_height = this->m_height + image.m_height;
	result.m_width = this->m_width + image.m_width;

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			result.m_data[i][j] = this->m_data[i][j] + image.m_data[i][j];
	//dealocare pentru 'this' ??
	return result;
}

Image Image::operator-(const Image& image)
{
	if (this->size() != image.size())
		throw exception();

	Image result;

	result.m_height = this->m_height + image.m_height;
	result.m_width = this->m_width + image.m_width;

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			result.m_data[i][j] = this->m_data[i][j] - image.m_data[i][j];
	//dealocare pentru 'this' ??
	return result;
}

Image Image::operator*(const Image& image)
{
	if (this->size() != image.size())
		throw exception();

	Image result;

	result.m_height = this->m_height + image.m_height;
	result.m_width = this->m_width + image.m_width;

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			result.m_data[i][j] = this->m_data[i][j] * image.m_data[i][j];
	//dealocare pentru 'this' ??
	return result;
}

bool Image::isEmpty() const
{
	if (this->m_height == 0 && this->m_width == 0)
		return true;
	return false;
}

Size Image::size() const
{
	return Size();
}

unsigned int Image::width() const
{
	return this->m_width;
}

unsigned int Image::height() const
{
	return this->m_height;
}

std::ostream& operator<<(std::ostream& os, const Image& dt)
{
	for (int i = 0; i < dt.m_height; i++) {
		for (int j = 0; j < dt.m_width; j++)
			os << dt.m_data[i][j] << " ";
		os << endl;
	}
	return os;
}
