#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "tokenizer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string str;
	if (!ReadLine(str)) {
		cout << "false" << endl;
	}
	else {
		cout << "true" << endl;
	}
}