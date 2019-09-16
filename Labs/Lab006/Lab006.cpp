/*
	Lab006.cpp
	Andrew Ng
	Sep 16 2019
	Lab 6 program for CS201
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printStringLength (string s)
{
	cout << "The string, " << s << ", has length: " << s.size() << endl;
}

int main()
{
	string userString;
	string finalString;
	cout << "Enter a string." << endl;
	cin >> userString;
	finalString = userString;
	for (int i = 0; i < 5; ++i) {
		printStringLength(finalString);
		finalString = finalString + userString;
	}
	return 0;
}