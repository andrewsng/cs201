/*
	names.cpp
	Andrew Ng
	Sep 16 2019
	10 Names program for hw2
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

int main()
{
	vector<string> names;
	string nameToFind;
	InputNames(names);
	cout << "Enter a name to search for." << endl;
	cin >> nameToFind;
	if (DoesNameExist(nameToFind, names) == true) {
		cout << "The name exists." << endl;;
	}
	else {
		cout << "The name doesn't exist." << endl;
	}

	return 0;
}