#include <iostream>
#include "Image.h"
using namespace std;

int main() {

	Image x(9999,9999);
	x.load("C:\\Users\\Andrei\\source\\repos\\BasicImageProcessingApp\\BasicImageProcessingApp\\hands.ascii.pgm");
	x.save("C:\\Users\\Andrei\\source\\repos\\BasicImageProcessingApp\\BasicImageProcessingApp\\RESULT.ascii.pgm");

	/*
	unsigned int x = 7, y = 3,z;
	z = y - x;
	cout << z;
	*/
	return 0;
}