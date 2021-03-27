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

	unsigned char& at(unsigned int x, unsigned int y);
	unsigned char& at(Point pt);

	unsigned char* row(int y);

	void release();//call in the destructor?

	friend std::ostream& operator<<(std::ostream& os, const Image& dt);

	static Image zeros(unsigned int width, unsigned int height);
	static Image ones(unsigned int width, unsigned int height);
private:
	unsigned char** m_data;
	unsigned int m_width;
	unsigned int m_height;
};

