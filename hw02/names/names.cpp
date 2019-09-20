/*
	names.cpp
	Andrew Ng
	Sep 16 2019
	10 Names program for hw2
*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void InputNames()
{
	vector<string> names;
	for (int i = 0; i < 10; i++) {
		string name;
		cout << "Please enter a name: " << endl;
		std::getline(cin, name);
		names.push_back(name);
	}
}

int main()
{

}