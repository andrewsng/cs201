/*
	money.cpp
	Andrew Ng
	Sep 22 2019
	Money counting program for hw2
*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
	int coinInput;
	int totalCents;
	vector<int> numCoins;
	vector<string> coin = { "penny", "nickel", "dime", "quarter", "one-dollar coin" };
	vector<string> coinPlural = { "pennies", "nickels", "dimes", "quarters", "one-dollar coins" };
	for (int i = 0; i < 5; ++i) {
		cout << "How many " << coinPlural[i] << " do you have?: ";
		cin >> coinInput;
		numCoins.push_back(coinInput);
	}
	cout << endl;
	for (int j = 0; j < 5; ++j) {
		cout << "You have " << numCoins[j] << " ";
		if (numCoins[j] == 1) {
			cout << coin[j] << "." << endl;
		}
		else {
			cout << coinPlural[j] << "." << endl;
		}
	}
	totalCents = (numCoins[0] * 1) + (numCoins[1] * 5) + (numCoins[2] * 10) + (numCoins[3] * 25) + (numCoins[4] * 100);
	cout << endl << "The value of all your coins is " << totalCents << " cents, or $" << totalCents / 100 << "." << totalCents % 100 << endl;
}