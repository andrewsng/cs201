/*
	names.cpp
	Andrew Ng
	Sep 16 2019
	Names program for hw2
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

int main()	// Prompts for various name inputs and calls functions
{
	vector<string> names;
	string nameToFind;
	cout << "Enter 10 Names." << endl;
	InputNames(names);
	cout << endl << "Enter a name to search for: ";
	std::getline(cin, nameToFind);
	if (DoesNameExist(nameToFind, names) == true) {
		cout << endl << "The name exists." << endl;;
	}
	else {
		cout << endl << "The name doesn't exist." << endl;
	}
	PrintNames(names);
	CountCharacters(names);
	return 0;
}