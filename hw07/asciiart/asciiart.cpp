#include <iostream>
#include <fstream>
#include <vector>
#include "Color3.hpp"
#include "Image3.hpp"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;



int main()
{
	Color3 newcolor(219, 219, 219);
	cout << "r " << newcolor.r << "g " << newcolor.g << "b " << newcolor.b << endl;
}