/*
random-map.cpp
Andrew Ng
Nov 17 2019
random distribution tests for hw 6
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>


using std::cout;
using std::endl;


// Takes in an int and two bounds
// Returns bounding value if outside of bounds
int clamp(int x, int a, int b)
{
	return (x < a) ? (a) : (x > b) ? (b) : (x);
}


// Makes uniform distribution using given range
// Returns one value generated with that distribution
int RandomBetweenU(int first, int last)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> udist(first, last);
	return udist(gen);
}


// Makes normal distribution using given range
// Returns one value generated with that distribution
int RandomBetweenN(int first, int last)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int mean = ((last - first) / 2) + 2;
	int stddev = mean / 3;
	std::normal_distribution<> ndist(mean, stddev);
	return clamp(ndist(gen), first, last);
}


// Returns value within a given range using rand() function
int RandomBetween(int first, int last)
{
	std::random_device rd;
	std::srand(rd());
	return rand() % (last - first + 1) + 1;
}


// Takes map storing how many times numbers were generated
// Prints map out as a histogram to show distribution
void PrintDistribution(const std::map<int, int>& numbers)
{
	for (auto p : numbers) {
		std::cout << std::setw(2)
			<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	}
	cout << endl;
}


// Generates maps to count generated numbers
// Calls function to print the distributions
int main()
{
	std::map<int, int> histU;
	for (int i = 0; i < 100000; ++i) {
		++histU[std::round(RandomBetweenU(1, 20))];
	}

	std::map<int, int> histN;
	for (int i = 0; i < 100000; ++i) {
		++histN[std::round(RandomBetweenN(1, 20))];
	}

	std::map<int, int> histR;
	for (int i = 0; i < 100000; ++i) {
		++histR[std::round(RandomBetween(1, 20))];
	}

	cout << "Uniform distribution between 1 and 20: " << endl;
	PrintDistribution(histU);

	cout << "Normal distribution between 1 and 20: " << endl;
	PrintDistribution(histN);

	cout << "rand() distribution between 1 and 20: " << endl;
	PrintDistribution(histR);
}