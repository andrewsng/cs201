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
	std::string newFile = "mandelbrot.ppm";
	Image3 mandelbrot(700, 400);
	for (double Py = 0.0; Py < mandelbrot.h; ++Py) {
		for (double Px = 0.0; Px < mandelbrot.w; ++Px) {
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
			cout << iteration << " ";
			Color3 newColor;
			newColor.r = saturate(iteration, 255);
			newColor.g = saturate(iteration, 10);
			newColor.b = saturate(iteration, 60);
			mandelbrot.setPixel((int)Px, (int)Py, newColor);
		}
	}
	mandelbrot.savePPM(newFile);
}