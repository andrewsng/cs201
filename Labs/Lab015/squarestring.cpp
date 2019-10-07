/*
	squarestring.cpp
	Andrew Ng
	Oct 7 2019
	source for square string function
*/

#include <iostream>
#include <string>
#include <sstream>
#include "squarestring.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool squareString(string squared)
{
	std::istringstream numstream(squared);
	double num;
	numstream >> num;
	if (!numstream) {
		return false;
	}
	else {
		cout << num * num << endl;
		return true;
	}
}