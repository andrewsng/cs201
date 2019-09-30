/*
	userInput.cpp
	Andrew Ng
	Sep 30 2019
	Function to get user strings for lab 12
*/

#include <iostream>
#include "userInput.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void getUserStrings(vector<string>& words)
{
	string givenWord;
	while (true) {
		cin >> givenWord;
		if (givenWord == "end") {
			break;
		}
		else {
			words.push_back(givenWord);
		}
	}
}

bool hasChar(const std::string& str, const char& c)
{
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == c) {
			return true;
		}
		return false;
	}
}