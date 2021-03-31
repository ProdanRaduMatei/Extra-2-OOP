#include "ImageProcessing.h"
#include "Image.h"
#include <exception>
#include <cmath>


#include <iostream>
using namespace std;

void ImageProcessing::process(const Image& src, Image& dst){}

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


void Convolution::setKernelIdentity() {
	kernel[0][0] = 0; kernel[0][1] = 0; kernel[0][2] = 0;
	kernel[1][0] = 0; kernel[1][1] = 1; kernel[1][2] = 0;
	kernel[2][0] = 0; kernel[2][1] = 0; kernel[2][2] = 0;
}

void Convolution::setKernelBlur() {
	kernel[0][0] = 1; kernel[0][1] = 1; kernel[0][2] = 1;
	kernel[1][0] = 1; kernel[1][1] = 1; kernel[1][2] = 1;
	kernel[2][0] = 1; kernel[2][1] = 1; kernel[2][2] = 1;
}

void Convolution::setKernelGaussian() {
	kernel[0][0] = 1; kernel[0][1] = 2; kernel[0][2] = 1;
	kernel[1][0] = 2; kernel[1][1] = 4; kernel[1][2] = 2;
	kernel[2][0] = 1; kernel[2][1] = 2; kernel[2][2] = 1;
}

void Convolution::setKernelHorizontal() {
	kernel[0][0] = 1; kernel[0][1] = 2; kernel[0][2] = 1;
	kernel[1][0] = 0; kernel[1][1] = 0; kernel[1][2] = 0;
	kernel[2][0] = -1; kernel[2][1] = -2; kernel[2][2] = -1;
}

void Convolution::setKernelVertical() {
	kernel[0][0] = -1; kernel[0][1] = 0; kernel[0][2] = 1;
	kernel[1][0] = -2; kernel[1][1] = 0; kernel[1][2] = 2;
	kernel[2][0] = -1; kernel[2][1] = 0; kernel[2][2] = 1;
}

int movx[9] = { -1,-1,-1,0,0,0,1,1,1 };
int movy[9] = { -1,0,1,-1,0,1,-1,0,1 };

int Convolution::csp(const Image& src, unsigned int x, unsigned int y) {

	setKernelBlur();//setKernelBlur
	int sum = 0, i2 = 0, j2 = 0;
	for (int i = 0; i < 9; i++) {
		if (j2 == 3) {
			j2 = 0;
			i2++;
		}
		if (movx[i] >= 0 && movy[i] >= 0 && (x + movx[i] < src.height()) && (y + movy[i] < src.width()))
			sum += src.getPixelVal(x + movx[i], y + movy[i]) * kernel[i2][j2];
		j2++;
	}
	return sum;
}


void Convolution::process(const Image& src, Image& dst) {
	for (int i = 0; i < dst.height(); i++) {
		for (int j = 0; j < dst.width(); j++) {
			dst.setPixelVal(i, j, csp(src, i, j));
		}
	}
	dst.setHeight(src.height());
	dst.setWidth(src.width());
}