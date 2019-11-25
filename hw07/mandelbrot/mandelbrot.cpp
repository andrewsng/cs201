/*
mandelbrot.cpp
Andrew Ng
Nov 25 2019
Using asciiart program to print
out mandelbrot set
*/


#include <iostream>
#include <string>
#include <vector>
#include "Color3.hpp"
#include "Image3.hpp"


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;


constexpr int saturate(int x, int maxvalue) {
	return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}


int main()
{
	// new file name
	std::string newFile = "mandelbrot.ppm";

	// new image of given res
	Image3 mandelbrot(700, 400);

	if (!mandelbrot.savePPM(newFile)) {
		cout << "ERROR: Could not export to given file" << endl;
		return 0;
	}

	// loop through all pixels
	for (double Py = 0.0; Py < mandelbrot.h; ++Py) {
		for (double Px = 0.0; Px < mandelbrot.w; ++Px) {

			// mandelbrot algorithm
			double x0 = Px / mandelbrot.w * 3.5 - 2.5;
			double y0 = (Py / mandelbrot.h) * 2.0 - 1.0;
			double x = 0.0;
			double y = 0.0;
			unsigned iteration = 0;
			unsigned max_iteration = 10000;
			while (((x * x) + (y * y)) <= 4.0 && iteration < max_iteration) {
				double xtemp = (x * x) - (y * y) + x0;
				y = (2.0 * x * y) + y0;
				x = xtemp;
				iteration++;
			}

			// outputting iteration values to console
			// for debugging
			cout << iteration << " ";

			// setting pixels to colors based on iterations
			// custom colors by clamping max rgb values
			Color3 newColor;
			newColor.r = saturate(iteration, 255);
			newColor.g = saturate(iteration, 10);
			newColor.b = saturate(iteration, 60);
			mandelbrot.setPixel((int)Px, (int)Py, newColor);
		}
	}
	// export to file
	mandelbrot.savePPM(newFile);
}