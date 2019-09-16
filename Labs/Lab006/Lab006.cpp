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

void printStringLength(string s)	//Takes in a string then prints the length
{
	cout << "The string, " << s << ", has length: " << s.size() << endl;
}

void printPounds(string s)	//Takes in a string and prints # characters to the same length
{
	cout << "The string, " << s << ", replaced with #'s is: ";
	for (int i = 0; i < s.size(); i++) {
		cout << "#";
	}
	cout << endl;
}

void printReverse(string s)	//Takes in a string and prints it reversed
{
	cout << "The string, " << s << ", in reverse is: ";
	for (int i = s.size()-1; i >= 0; --i) {
		cout << s[i];
	}
	cout << endl;
}

int main()	//Takes user input as a string and calls the different functions
{
	string userString;
	string finalString;
	cout << "Enter a string." << endl;
	cin >> userString;
	finalString = userString;
	for (int i = 0; i < 5; ++i) {	//Creating strings of various length by adding input to itself
		printStringLength(finalString);
		printPounds(finalString);
		printReverse(finalString);
		finalString = finalString + userString;
		cout << endl;
	}
	return 0;
}