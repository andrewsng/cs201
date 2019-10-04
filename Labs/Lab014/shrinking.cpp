/*
	shrinking.cpp
	Andrew Ng
	Oct 4 2019
	shrinking functions for lab 14
*/

#include <iostream>
#include <string>
#include "shrinking.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void shrinkStr(string shrunkStr)
{
	for (int i = shrunkStr.size(); i > 0; --i) {
		cout << shrunkStr.substr(0, i) << endl;
	}
}

void strCone(string shrunkStr)
{
	string spaces(shrunkStr.size(), ' ');
	for (int i = 0; i < (shrunkStr.size() / 2) + 1; ++i) {
		cout << spaces.substr(0, i) << shrunkStr.substr(i, shrunkStr.size() - (2 * i)) << endl;
	}
}