/*
	Lab036.cpp
	Andrew Ng
	Dec 2 2019
	Lab 36 for cs201
*/


#include <iostream>


using std::cout;
using std::endl;


const int flag1 = 1;
const int flag2 = 2;
const int flag3 = 4;
const int flag4 = 8;
const int flag5 = 16;


void outFlag(int num)
{
	cout << "Flags that are set: " << endl;
	if (num & flag1) {
		cout << "Flag 1" << endl;
	}
	if (num & flag2) {
		cout << "Flag 2" << endl;
	}
	if (num & flag3) {
		cout << "Flag 3" << endl;
	}
	if (num & flag4) {
		cout << "Flag 4" << endl;
	}
	if (num & flag5) {
		cout << "Flag 5" << endl;
	}

	if (num & (flag1 | flag2)) {
		cout << "One of the flags is set" << endl;
	}
}


int main()
{
	outFlag(flag1 | flag3);
	outFlag(flag2);
	outFlag(flag3 | flag4 | flag5);
	cout << endl;

	cout << "Size of double is " << sizeof(double) << " bytes" << endl;
	cout << "Size of double is " << sizeof(double) * 8 << " bits" << endl;
	cout << endl;

	outFlag(flag1);
	outFlag(flag2);
	outFlag(flag1 | flag2);
	outFlag(flag3);
}