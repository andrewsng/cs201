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
	int boxWidth = (thickness * 2) + (boxString.size()) + 2;
	const int inputSpot = thickness + 1;
	string filledLine(boxWidth, '*');
	string spacedLine = filledLine;
	spacedLine.replace(thickness, (boxString.size() + 2), (boxString.size() + 2), ' ');
	string inputLine = spacedLine;
	inputLine.replace(inputSpot, boxString.size(), boxString);
	printLines(filledLine, thickness);
	printLines(spacedLine, 1);
	printLines(inputLine, 1);
	printLines(spacedLine, 1);
	printLines(filledLine, thickness);
}

void printLines(const string printedString, const int timesToPrint)
{
	for (int i = 0; i < timesToPrint; ++i) {
		cout << printedString << endl;
	}
}