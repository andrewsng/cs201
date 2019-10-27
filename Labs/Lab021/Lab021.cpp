/*
	Lab021.cpp
	Andrew Ng
	Oct 23 2019
	lab 21 main for cs201
*/

#include <iostream>
#include <string>
#include "truncstruct.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str;
	int len;
	cin >> str;
	cin >> len;
	StringInfo inputs{ str, len };
	StringInfo result = trunc(inputs);
	cout << result.str << endl;
}