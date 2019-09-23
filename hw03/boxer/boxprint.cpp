/*
	boxprint.cpp
	Andrew Ng
	Sep 23 2019
	Main box printing program for hw3
*/

#include <iostream>
#include <string>
#include "boxer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string boxString;
	int thickness;
	std::getline(cin, boxString);
	cin >> thickness;
	printBox(boxString, thickness);
}