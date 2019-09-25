/*
	Lab010.cpp
	Andrew Ng
	Sep 25 2019
	Lab010 main for CS201
*/

#include <iostream>
#include "lab010functions.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a;
	int b;
	cout << "Enter integers a and b to get all integers between 1 and a that are divisible by b." << endl;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	isADivB(a, b);
}

/*
PART 1

for (int i = 1; i <= 40; ++i) {
	if (isDiv3(i)) {
		cout << i << endl;
	}
}
*/