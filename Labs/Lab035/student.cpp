/*
student.cpp
Andrew Ng
Nov 25 2019
source code for class functions
for lab 35
*/


#include <iostream>
#include "student.hpp"


using std::cout;
using std::endl;


void Student::printInfo() const
{
	cout << "Name is: " << name_ << endl;
	cout << "ID is: " << id_ << endl;
}