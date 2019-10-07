#include <iostream>
#include <string>
#include <sstream>
#include "squarestring.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void squareString(string squared)
{
	std::istringstream numstream(squared);
	double num;
	numstream >> num;
	if (!numstream) {
		cout << "ERROR: String did not begin with a number" << endl;
	}
	else {
		cout << num * num << endl;
	}
}