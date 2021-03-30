#pragma once
#include "Image.h"
#include "Point.h"
#include "Rectangle.h"

void drawCircle(Image& img, Point center, int radius, unsigned int color);

void drawLine(Image& img, Point p1, Point p2, unsigned int color);

void drawRectangle(Image& img, Rectangle r, unsigned int color);

void drawRectangle(Image& img, Point tl, Point br, unsigned int color);
