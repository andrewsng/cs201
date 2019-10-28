/*
	Lab023.cpp
	Andrew Ng
	Oct 28 2019
	Lab 23 for cs201
*/

#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;

int main()
{
	map<string, int> names;
	names["Bob"] = 23;
	names["Joe"] = 9;
	names["Bill"] = 12;
	names["Frank"] = 41;
	names["Sam"] = 54;

	names.erase("Frank");

	for (const auto& m : names) {
		cout << "Key: " << m.first << " Value: " << m.second << endl;
	}
}