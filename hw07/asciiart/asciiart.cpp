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


int main()
{
	std::string fileName = "parrot.ppm";
	std::string newFile = "newparrot.ppm";
	Image3 parrot;
	if (!parrot.loadPPM(fileName)) {
		cout << "ERROR: File Cannot be Opened" << endl;
	}
	parrot.printASCII(cout);
	parrot.savePPM(newFile);
}