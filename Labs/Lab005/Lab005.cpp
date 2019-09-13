/*
	Lab005.cpp
	Andrew Ng
	Sep 13 2019
	Lab 5 for CS201
	*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int optionNum;
	while (true) {
		cout << "What would you like to do?\n"
			<< "1. Option 1\n"
			<< "2. Option 2\n"
			<< "3. Option 3\n"
			<< "4. Exit Program" << endl;
		cin >> optionNum;
		switch (optionNum) {
		case 1:
			cout << "You picked option 1." << endl;
			continue;
		case 2:
			cout << "You picked option 2." << endl;
			continue;
		case 3:
			cout << "You picked option 3." << endl;
			continue;
		case 4:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "That's not an available option." << endl;
			continue;
		}
		break;
	}
}