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
	std::string fileName = "\"parrot.ppm\"";
	Image3 parrot;
	parrot.loadPPM(fileName);
	
	//fin >> parrot;

}