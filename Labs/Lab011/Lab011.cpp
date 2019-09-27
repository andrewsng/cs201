/*
	Lab011.cpp
	Andrew Ng
	Sep 27 2019
	Lab 11 program for CS201
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string inputString;
	vector<char> lowercase;
	vector<char> uppercase;
	vector<char> symbols;
	cin >> inputString;
	for (unsigned int i = 0; i < inputString.size(); ++i) {
		if (inputString[i] >= 'a' && inputString[i] <= 'z') {
			lowercase.push_back(inputString[i]);
		}
		else if (inputString[i] >= 'A' && inputString[i] <= 'Z') {
			uppercase.push_back(inputString[i]);
		}
		else {
			symbols.push_back(inputString[i]);
		}
	}
	for (auto i : lowercase) {
		cout << i;
	}
	cout << endl;
	for (auto i : uppercase) {
		cout << i;
	}
	cout << endl;
	for (auto i : symbols) {
		cout << i;
	}
	cout << endl;
}