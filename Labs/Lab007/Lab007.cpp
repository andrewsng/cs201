/*
	Lab007.cpp
	Andrew Ng
	Sep 18 2019
	Lab 7 program for CS201
*/

#include <iostream>
#include "intio.hpp"

using std::cin;
using std::cout;
using std::endl;

void part1()
{
	cout << "Enter 3 integers." << endl;
	int num1 = getInt();
	int num2 = getInt();
	int num3 = getInt();
	putInt(num1, 10);
	cout << endl;
	putInt(num2, 10);
	cout << endl;
	putInt(num3, 10);
	cout << endl;
}

void part2()
{
	cout << "Enter integers to get their sum. Enter 0 to stop." << endl;
	int result = 0;
	int added;
	do {
		added = getInt();
		result = result + added;
	} while (added != 0);
	putInt(result, 10);
	cout << endl;
}

void part3()
{
	cout << "Enter integers to get the smallest number. Enter 0 to stop." << endl;
	int smallest = getInt();
	int num;
	do {
		num = getInt();
		if (num < smallest && num != 0) {
			smallest = num;
		}
	} while (num != 0);
	putInt(smallest, 10);
	cout << endl;
}

int main()
{
	part1();
	cout << endl;
	part2();
	cout << endl;
	part3();
	cout << endl;
	return 0;
}