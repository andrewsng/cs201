#include <iostream>
#include "vector_manip.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;

void printVector(vector<string> & strVec)
{
	for (auto & s : strVec) {
		cout << s << " ";
	}
	cout << endl;
}

void firstLetterChange(std::vector<std::string>& strVec, const char& c)
{
	for (auto & s : strVec) {
		s[0] = c;
	}
	
}

void addUserStrings(std::vector<std::string>& strVec,
	const std::string sentinel)
{

}