/*
	namefunctions.cpp
	Andrew Ng
	Sep 22 2019
	Name function definitions for hw2
*/

#include <iostream>
#include <vector>
#include <string>
#include "namefunctions.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void InputNames(vector<string> &names)
{
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}
}

bool DoesNameExist(const string &nameToFind, const vector<string> &names)
{
	for (string name : names) {
		if (name == nameToFind) {
			return true;
		}
		else {
			return false;
		}
	}
}