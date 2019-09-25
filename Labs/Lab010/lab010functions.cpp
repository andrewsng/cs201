#include <iostream>
#include "lab010functions.h"

using std::cout;
using std::endl;

bool isDiv3(int i)
{
	if (i % 3 == 0) {
		return true;
	}
	else {
		return false;
	}
}

void isADivB(int a, int b)
{
	for (int i = 1; i <= a; ++i) {
		if (i % b == 0) {
			cout << i << endl;
		}
	}
}