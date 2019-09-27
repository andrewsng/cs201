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
	while (true) {
		cout << "Take a line and put it in a box!" << endl;
		cout << "Enter the line you want in the box, or type Exit to stop:" << endl;
		std::getline(cin, boxString);
		if (boxString == "Exit") {
			break;
		}
		cout << "Enter a positive integer for the thickness of the box." << endl;
		cin >> thickness;
		while (cin.fail() || thickness <= 0) {
			std::cerr << "You did not enter a positive integer. Try again." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> thickness;
		}
		printBox(boxString, thickness);
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}