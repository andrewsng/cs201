/*
	Lab008.cpp
	Andrew Ng
	Sep 20 2019
	Lab 8 Functions for CS201
*/

#include "intio.hpp"

int doInput()
{
	return getInt();
}

int compute(int n)
{
	int num = 0;
	if (n <= 0) {
		return 0;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				num++;
			}
		}
		return num;
	}
}