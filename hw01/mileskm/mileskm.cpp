/*
	mileskm.cpp
	Andrew Ng
	Sep 15 2019
	Miles to kilometers conversion program for hw1
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	float miles, kilometers;
	cout << "Enter a number of miles that you want to convert to kilometers." << endl;
	cin >> miles;
	kilometers = miles * 1.609;
	cout << miles << " mi. converted to kilometers = " << kilometers << " km." << endl;
	return 0;
}