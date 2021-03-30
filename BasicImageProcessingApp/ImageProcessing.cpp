#include "ImageProcessing.h"
#include "Image.h"
#include <exception>
#include <cmath>


#include <iostream>
using namespace std;

void ImageProcessing::process(const Image& src, Image& dst){}

/*
BrightnessContrastAdjustment::BrightnessContrastAdjustment()
{
	this->contrast = 1;
	this->brightness = 0;
}

BrightnessContrastAdjustment::BrightnessContrastAdjustment(int contrast, int brightness)
{
	this->contrast = contrast;
	this->brightness = brightness;
}*/

Adjustment::Adjustment()
{
	this->contrast = 1;
	this->brightness = 0;
}

void Adjustment::setContrast(float c)
{
	this->contrast = c;
}

void Adjustment::setBrightness(int b)
{
	this->brightness = b;
}

void Adjustment::process(const Image& src, Image& dst)
{
	for (int i = 0; i < src.height(); i++)
		for (int j = 0; j < src.width(); j++)
			dst.setPixelVal(j, i, this->contrast * src.getPixelVal(j, i) + this->brightness);
}

Gamma::Gamma()
{
	this->tita = 1;
}

void Gamma::setTita(float t)
{
	this->tita = t;
}

void Gamma::process(const Image& src, Image& dst)
{
	for (int i = 0; i < src.height(); i++)
		for (int j = 0; j < src.width(); j++)
			dst.setPixelVal(j, i,pow(src.getPixelVal(j, i),this->tita));
}
