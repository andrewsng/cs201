/*
	quadratic.cpp
	Andrew Ng
	Sep 29 2019
	Quadratic formula program for hw 3
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	double a, b, c;
	double xPlus, xMinus;
	cout << "Solve the quadratic equation of form ax^2 + bx + c" << endl;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;
	if ((b * b) - (4 * a * c) < 0) { // checking for non-real solutions
		cout << "Your quadratic has no real solutions." << endl;
	}
	else {
		xPlus = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
		xMinus = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);
		cout << "The solutions are " << xPlus << " and " << xMinus << endl;
	}
}