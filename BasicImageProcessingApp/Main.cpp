#include <iostream>
#include "Image.h"
#include "Rectangle.h"
#include "ImageProcessing.h"
#include "drawingModule.h"

using namespace std;

int main() {

	Image x(9999, 9999);
	Rectangle r(100, 100, 100, 130);
	Point P1(200, 321),P2(460,340);
	x.load("C:\\Users\\Andrei\\source\\repos\\BasicImageProcessingApp\\BasicImageProcessingApp\\gator.ascii.pgm");

	//x.getROI(x, 160, 120, 320, 240);
	//x.getROI(x,r);

	//Adjustment adj;
	//adj.setBrightness(-100);
	//adj.setContrast(1);
	//adj.process(x, x);

	//Gamma gm;
	//gm.setTita(0.5);
	//gm.process(x,x);

	//drawCircle(x, center, 100, 0);
	//drawLine(x, P1, P2, 0);
	//drawRectangle(x, r, 0);
	//drawRectangle(x, P1, P2, 0);

	x.save("C:\\Users\\Andrei\\source\\repos\\BasicImageProcessingApp\\BasicImageProcessingApp\\RESULT.ascii.pgm");

	return 0;
}