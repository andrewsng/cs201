/*
	Lab003.cpp
	Andrew Ng
	Sep 9, 2019
	CS201 Lab 3
*/
#include <iostream>

using std::cout;
using std::endl;

void part1()
{
	int i = 1;
	while (i <= 20) {
		cout << i << endl;
		i++;
	}
}

void part2()
{
	int boxH = 1, boxW = 1;
	while (boxH <= 10) {
		while (boxW <= 60) {
			cout << "*";
			boxW++;
		}
		cout << endl;
		boxW = 1;
		boxH++;
	}
}

void part3()
{
	int box2H = 1, box2W = 1, j = 1;
	while (box2H <= 10) {
		while (box2W <= 60) {
			if ((j % 2) != 0) {
				cout << "*";
			}
			else {
				cout << "#";
			}
			j++;
			box2W++;
		}
		j++;
		cout << endl;
		box2W = 1;
		box2H++;
	}
}

int main()
{
	part1();
	part2();
	part3();
	return 0;
}