/*
	Lab015.cpp
	Andrew Ng
	Oct 7 2019
	main function for lab 15
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "squarestring.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> testNumbers{ "69", "69a", "a69", "5.6", "    68", "\t11", "68 69", "0xA"};
	for (auto s : testNumbers) {
		if (!squareString(s)) {
			cout << "ERROR: String did not begin with a number" << endl;
		}
	}
	return 0;
}