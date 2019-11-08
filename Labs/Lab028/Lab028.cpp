/*
	Lab028.cpp
	Andrew Ng
	Nov 8 2019
	Lab 28 for cs201
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>

using std::cout;
using std::endl;
using std::ofstream;
using std::setw;
using std::vector;
using std::mt19937;

void printIntegersToFile(const vector<int>& integers, std::ofstream& output);

void printIntegersToFile(const vector<int>& integers, std::ofstream& output)
{
	int count = 1;
	for (const auto n : integers) {
		output << setw(4) << n;
		if (count % 10 == 0) {
			output << "\n";
		}
		count++;
	}
}

int main()
{
	ofstream fout("numbers.txt");
	ofstream shuffle("shuffled.txt");
	vector<int> integers;
	for (int i = 1; i <= 100; ++i) {
		fout << setw(4) << i;
		if (i % 10 == 0) {
			fout << "\n";
		}
		integers.push_back(i);
	}
	std::random_device rd;
	mt19937 gen(rd());
	std::shuffle(integers.begin(), integers.end(), gen);
	printIntegersToFile(integers, shuffle);
}