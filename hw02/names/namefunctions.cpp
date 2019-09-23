/*
	namefunctions.cpp
	Andrew Ng
	Sep 22 2019
	Name function definitions for hw2
*/

#include "namefunctions.h"
#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void InputNames(vector<string> & names)
{
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}
}