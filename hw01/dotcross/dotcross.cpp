/*
	dotcross.cpp
	Andrew Ng
	Sep 15 2019
	Dot product and cross product program for hw1
*/
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	float Ax, Ay, Az;
	float Bx, By, Bz;
	float Cx, Cy, Cz;
	cout << "Enter the three components of your first vector, A, separately." << endl;
	cin >> Ax >> Ay >> Az;
	cout << "Enter the three components of your second vector, B, separately." << endl;
	cin >> Bx >> By >> Bz;
	Cx = (Ay * Bz) - (Az * By);
	Cy = (Az * Bx) - (Ax * Bz);
	Cz = (Ax * By) - (Ay * Bx);
	cout << std::setprecision(5) << std::fixed << "A dot B = " << (Ax * Bx) + (Ay * By) + (Az * Bz) << endl;
	cout << std::setprecision(5) << std::fixed << "A cross B = <" << Cx << ", " << Cy << ", " << Cz << ">" << endl;
	return 0;
}