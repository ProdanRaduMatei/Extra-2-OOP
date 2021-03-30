#include "drawingModule.h"
#include <cmath>

float distance(Point P1, Point P2) {
	return sqrtf((P2.getX() - P1.getX()) * (P2.getX() - P1.getX()) + (P2.getY() - P1.getY()) * (P2.getY() - P1.getY()));
}

void drawCircle(Image& img, Point center, int radius, unsigned int color)
{
	for (int i = 0; i < img.height(); i ++) {
		for (int j = 0; j < img.width(); j++) {
			Point P(j,i);
			float d = distance(center, P);//compute distance
			if(radius-1 <= d && d <= radius+1)//allow a little error
				img.setPixelVal(j, i, color);
		}
	}
}

void drawLine(Image& img, Point p1, Point p2, unsigned int color)
{
	for (int i = 0; i < img.height(); i++) {
		for (int j = 0; j < img.width(); j++) {
			int equation = j * p1.getY() + p1.getX() * p2.getY() + i * p2.getX() - p2.getX()*p1.getY() - j*p2.getY() - i*p1.getX();
			if(-75 <= equation && equation <= 75)
				img.setPixelVal(j, i, color);
		}
	}
}
