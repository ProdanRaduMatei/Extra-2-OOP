#pragma once
#include <iostream>
#include "Size.h"
#include "Rectangle.h"
#include "Point.h"

class Image
{
public:
	Image();//default constructor
	Image(unsigned int w, unsigned int h);//constructor that initializes
	Image(const Image& other);//copy constructor
	~Image();//destructor
	void release();

	bool load(std::string imagePath);
	bool save(std::string imagePath);

	Image& operator=(const Image& other);//copy assignment operator
		
	Image operator+(const Image& i);
	Image operator-(const Image& i);
	Image operator*(const Image& i);

	bool getROI(Image& roiImg, Rectangle roiRect);
	bool getROI(Image& roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

	bool isEmpty() const;

	Size size() const;

	unsigned int width() const;
	unsigned int height() const;
	unsigned int getPixelVal(int x, int y) const;
	void setPixelVal(int x, int y, float val) const;

	unsigned int& at(unsigned int x, unsigned int y);
	unsigned int& at(Point pt);

	unsigned int* row(int y);

	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);

private:
	unsigned int** m_data;
	unsigned int m_width;
	unsigned int m_height;
};

