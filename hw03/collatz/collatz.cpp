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

void collatz(int& n)
{
	while (n != 1) {
		if (n % 2 == 0) {
			n = (n / 2);
			cout << n << " ";
		}
		else {
			n = (3 * n) + 1;
			cout << n << " ";
		}
	}
	cout << n << endl;
}

int main()
{
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		else if (cin.fail() || n < 0) {
			std::cerr << "You did not enter a positive integer. Try again." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			collatz(n);
		}
	}
}