/*
	Lab027.cpp
	Andrew Ng
	Nov 6 2019
	lab 27 for cs201
*/

#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribCoin(0, 1);
	int heads = 0;
	int tails = 0;
	for (int i = 0; i < 1000; ++i) {
		if (distribCoin(gen) == 0) {
			cout << "Heads" << endl;
			heads++;
		}
		else {
			cout << "Tails" << endl;
			tails++;
		}
	}
	cout << endl << heads << " Heads, and " << tails << " Tails." << endl;
}