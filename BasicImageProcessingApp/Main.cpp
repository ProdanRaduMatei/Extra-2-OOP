#include <iostream>
#include "Image.h"
#include "Rectangle.h"

using namespace std;

int main() {

	Image x(9999,9999);
	Rectangle r(160, 120, 320, 240);
	x.load("C:\\Users\\Andrei\\source\\repos\\BasicImageProcessingApp\\BasicImageProcessingApp\\hands.ascii.pgm");
	x.getROI(x, 160, 120, 320, 240);
	//x.getROI(x,r);
	x.save("C:\\Users\\Andrei\\source\\repos\\BasicImageProcessingApp\\BasicImageProcessingApp\\RESULT.ascii.pgm");

	/*
	unsigned int x = 7, y = 3,z;
	z = y - x;
	cout << z;
	*/
	return 0;
}