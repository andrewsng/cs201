/*
	main.cpp
	Andrew Ng
	Oct 4 2019
	main source for lab 14
*/

#include <iostream>
#include <string>
#include "shrinking.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string shrunkStr;
	cin >> shrunkStr;
	shrinkStr(shrunkStr);
	cout << endl;
	strCone(shrunkStr);
}