#include <iostream>
#include <string>
#include "modifyString.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string stringInMain = "Hello";
	cout << "Length: " << modifyString(stringInMain, 0) << endl;
	cout << "stringInMain: " << stringInMain << endl;
}