#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdlib.h>


using std::cout;
using std::endl;


int clamp(int x, int a, int b) {
	return (x < a) ? (a) : (x > b) ? (b) : (x);
}


int RandomBetweenU(int first, int last)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> udist(first, last);
	return udist(gen);
}


int RandomBetweenN(int first, int last)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int mean = ((last - first) / 2) + 2;
	int stddev = mean / 3;
	std::normal_distribution<> ndist(mean, stddev);
	return clamp(ndist(gen), first, last);
}


int RandomBetween(int first, int last)
{
	return 0;
}


void PrintDistribution(const std::map<int, int>& numbers)
{
	for (auto p : numbers) {
		std::cout << std::setw(2)
			<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	}
	cout << endl;
}


int main()
{
	std::random_device rd;

	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	cout << "Randomly-chosen mean is " << mean << endl;

	std::seed_seq seed2{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist(mean, 2);

	std::map<int, int> hist;
	for (int i = 0; i < 10000; ++i) {
		++hist[std::round(normal_dist(e2))];
	}
	for (auto p : hist) {
		std::cout << std::setw(2)
			<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	}
	std::map<int, int> histU;
	for (int i = 0; i < 10000; ++i) {
		++histU[std::round(RandomBetweenU(1, 6))];
	}
	std::map<int, int> histN;
	for (int i = 0; i < 10000; ++i) {
		++histN[std::round(RandomBetweenN(1, 6))];
	}
	std::map<int, int> histR;
	for (int i = 0; i < 10000; ++i) {
		++histR[std::round(RandomBetween(1, 6))];
	}
	PrintDistribution(histU);
	PrintDistribution(histN);
	//PrintDistribution(histR);
}