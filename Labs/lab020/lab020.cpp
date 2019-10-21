/*
	lab020.cpp
	Andrew Ng
	Oct 21 2019
	lab 20 for cs201
*/

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::setprecision;

int main()
{
	for (int i = 0; i <= 180; i += 5) {
		cout << setw(3) << i << " "
			<< setw(11) << setprecision(8) << std::fixed 
			<< cos(i * (M_PI / 180.)) << endl;
	}
}