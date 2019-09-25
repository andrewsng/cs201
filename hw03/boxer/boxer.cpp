/*
	boxer.cpp
	Andrew Ng
	Sep 23 2019
	Boxer function for hw3
*/

#include <iostream>
#include <string>
#include "boxer.h"

using std::cout;
using std::endl;
using std::string;

void printBox(const std::string boxString, int thickness)
{
	int boxWidth = (thickness * 2) + (boxString.length()) + 2;
	string filledLine(boxWidth, '*');
	string spacedLine = filledLine;
	spacedLine.replace(thickness, (boxString.length() + 2), (boxString.length() + 2), ' ');
	string inputLine = spacedLine;
	const int i = thickness + 2;
	inputLine.replace(i, boxString.length(), boxString);
	cout << filledLine << endl;
	cout << spacedLine << endl;
	cout << inputLine << endl;

}

void printLine(const int boxWidth, const int thickness)
{

}