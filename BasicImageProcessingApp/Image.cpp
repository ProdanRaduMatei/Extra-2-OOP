#include "Image.h"
#include "Size.h"
#include <exception>

using namespace std;

Image::Image()
{
	this->m_width = 0;
	this->m_height = 0;
	this->m_data = new unsigned int*[10];
	for (int i = 0; i < 10; i++)
		this->m_data[i] = new unsigned int[0];
	
}

Image::Image(unsigned int w, unsigned int h)
{
	this->m_width = w;
	this->m_height = h;
	this->m_data = new unsigned int*[h];
	for (int i = 0; i < h; i++)
		this->m_data[i] = new unsigned int[w];
}

Image::Image(const Image& other)
{
	if (this->m_height != other.m_height || this->m_width != other.m_width)
		throw exception();

	this->m_height = other.m_height;
	this->m_width = other.m_width;

	this->release();
	delete[] this->m_data;
	this->m_data = new unsigned int* [this->m_height];
	for (int i = 0; i < this->m_height; i++)
		this->m_data[i] = new unsigned int[this->m_width];

	for (int i = 0; i < this->m_height ; i++)
		for (int j = 0; j < this->m_width; j++)
			this->m_data[i][j] = other.m_data[i][j];
}

Image::~Image()
{
	this->release();
	delete[] m_data;
}

Image& Image::operator=(const Image& other)
{
	if (this == &other)
		return *this;
	this->m_height = other.m_height;
	this->m_width = other.m_width;

	this->release();
	delete[] this->m_data;
	this->m_data = new unsigned int* [this->m_height];
	for (int i = 0; i < this->m_height; i++)
		this->m_data[i] = new unsigned int[this->m_width];

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			this->m_data[i][j] = other.m_data[i][j];

	return *this;
}

Image Image::operator+(const Image& image)
{
	if (this->size() < image.size())
		throw exception();

	Image result(this->size().getWidth(), this->size().getHeight());

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			result.m_data[i][j] = this->m_data[i][j] + image.m_data[i][j];

	return result;
}

Image Image::operator-(const Image& image)
{
	if (this->size() < image.size())
		throw exception();

	Image result(this->size().getWidth(), this->size().getHeight());

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			result.m_data[i][j] = this->m_data[i][j] - image.m_data[i][j];

	return result;
}

Image Image::operator*(const Image& image)
{
	if (this->size() < image.size())
		throw exception();

	Image result(this->size().getWidth(), this->size().getHeight());

	for (int i = 0; i < this->m_height; i++)
		for (int j = 0; j < this->m_width; j++)
			result.m_data[i][j] = this->m_data[i][j] * image.m_data[i][j];

	return result;
}

bool Image::getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height)/////////INCOMPLETE
{
	if (roiImg.size().getWidth() < width || roiImg.size().getHeight() < height)
		return false;

	Image toReturn(width, height);





	return false;
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

unsigned int& Image::at(unsigned int x, unsigned int y)
{
	return this->m_data[x][y];
}

unsigned int& Image::at(Point pt)
{
	return this->m_data[pt.getX()][pt.getY()];
}

unsigned int* Image::row(int y)
{
	return m_data[y];
}

void Image::release()
{
	for (int i = m_height - 1; i >= 0; i--)
		delete[] m_data[i];
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
