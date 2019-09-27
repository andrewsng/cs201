/*
	collatz.cpp
	Andrew Ng
	Sep 27 2019
	Collatz sequence program for hw 3
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int collatz(int& n)
{
	if (n % 2 == 0) {
		return (n / 2);
	}
	else {
		return (3 * n) + 1;
	}
}

int main()
{
	int n;
	cin >> n;
	while (true) {
		cout << n << " ";
		if (n == 1) {
			break;
		}
		n = collatz(n);
	}
}