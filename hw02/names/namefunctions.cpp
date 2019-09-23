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

void InputNames(vector<string>& names)
{
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name: ";
		std::getline(cin, name);
		names.push_back(name);
	}
}

bool DoesNameExist(const string& nameToFind, const vector<string>& names)
{
	for (vector<string>::const_iterator it = names.begin(); it != names.end(); ++it) {
		if (*it == nameToFind) {
			return true;
		}
		else {
			continue;
		}
	}
	return false;
}

void PrintNames(const vector<string>& names)
{
	cout << endl << "The names in this list are: " << endl;
	for (vector<string>::const_iterator it = names.begin(); it != names.end(); ++it) {
		cout << *it << endl;
	}
}

void CountCharacters(const vector<string>& names)
{
	int numChar = 0;
	cout << endl;
	for (vector<string>::const_iterator it = names.begin(); it != names.end(); ++it) {
		for (int i = 0; i < (*it).length(); ++i) {
			if ((*it)[i] != ' ') {
				numChar++;
			}
		}
		cout << "The number of characters in the name, " << *it << " is: " << numChar << endl;
		numChar = 0;
	}
}