// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include "Image3.hpp"

Image3::Image3() : w(0), h(0)
{
}

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height) {
	// TODO: resize the pixels array
	// TODO: initialize the internal w and h members
	Color3 empty;
	pixels.resize(3 * width * height, empty);
	w = width;
	h = height;
}

// Return a pixel from the image
const Color3& Image3::getPixel(unsigned x, unsigned y) const {
	// TODO: Add error handling for unknown pixels
	// TERRIBLE OPTION 1: throw
	// BETTER OPTION 2: return a color
	// Hint: maybe this is already in the class?

	return pixels[y * w + x];
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) {
	// TODO: Set the pixel to the new color
	pixels[y * w + x] = color;
}

bool Image3::savePPM(const std::string& path) const {
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	std::ofstream fout(path);
	if (!fout) {
		return false;
	}
	fout << *this;
	return true;
}

bool Image3::loadPPM(const std::string& path) {
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	std::ifstream fin(path);
	if (!fin) {
		return false;
	}
	fin >> *this;
	return true;
}

void Image3::printASCII(std::ostream& ostr) const {
	// TODO: Print an ASCII version of this image
	for (unsigned y = 0; y < h; ++y) {
		for (unsigned x = 0; x < w; ++x) {
			unsigned luminance = pixels[y * w + x].weightedSum();
			std::cout << pixels[y * w + x].asciiValue(luminance);
		}
		std::cout << "\n";
	}
}

// STREAM OPERATORS for IMAGE3 class

std::ostream& operator<<(std::ostream& ostr, const Image3& image) {
	// TODO: Write out PPM image format to stream
	// ASSUME FORMAT WILL BE GOOD
	ostr << "P3\n";
	ostr << image.w << ' ';
	ostr << image.h << '\n';
	unsigned max = 255;
	ostr << max << '\n';
	for (unsigned y = 0; y < image.h; ++y) {
		for (unsigned x = 0; x < image.w; ++x) {
			ostr << image.pixels[y * image.w + x];
			ostr << '\n';
		}
	}
	return ostr;
}

std::istream& operator>>(std::istream& istr, Image3& image) {
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!
	std::string id;
	istr >> id;
	if (id != "P3") {
		std::cout << "ERROR: Bad File Format" << std::endl;
	}
	while (true) {
		char c;
		istr >> c;
		if (c == '#') {
			istr.ignore(1000000, '\n');
		}
		else {
			istr.putback(c);
			break;
		}
	}
	istr >> image.h;
	istr >> image.w;
	Color3 empty;
	image.pixels.resize(3 * image.w * image.h, empty);
	unsigned max;
	istr >> max;
	for (unsigned y = 0; y < image.h; ++y) {
		for (unsigned x = 0; x < image.w; ++x) {
			Color3 newColor;
			istr >> newColor;
			image.setPixel(x, y, newColor);
		}
	}
	return istr;
}
