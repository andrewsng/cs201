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

// Takes in an int and prints out the collatz sequence at that starting int
void collatz(int& n)
{
	while (n != 1) {
		cout << n << " ";
		if (n % 2 == 0) {
			n = (n / 2);
		}
		else {
			n = (3 * n) + 1;
		}
	}
	cout << n << endl;
}

// Repeatedly checks user input for positive int and calls collatz function
int main()
{
	int n;
	cout << "Enter a positive integer for the Collatz sequence starting there." << endl;
	cout << "Enter 0 to quit." << endl << endl;
	while (true) {
		cin >> n;
		if (cin.fail() || n < 0) {
			std::cerr << "You did not enter a positive integer. Try again." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (n == 0) {
			break;
		}
		else {
			collatz(n);
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}