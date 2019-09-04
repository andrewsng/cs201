/*
	squareNext.cpp
	Andrew Ng
	4 Sep 2019
	Square next integer program for lab 02
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int notSquared, nextInt, Squared;
	cout << "Please type in an integer." << endl;
	cin >> notSquared;
	nextInt = notSquared + 1;
	Squared = pow(nextInt, 2);
	cout << "The square of the next integer, " << nextInt << ", is: " << Squared << endl;
	return 0;
}