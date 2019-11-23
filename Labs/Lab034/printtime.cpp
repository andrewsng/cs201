/*
printtime.cpp
Andrew Ng
Nov 22 2019
Lab 34 for cs201
*/


// printtime.cpp  INCOMPLETE
// Glenn G. Chappell
// 20 Apr 2018
//
// For CS 201 Spring 2018
// Time of Day Class & Program
//
// Modified 11/28/18 for CS 201 Fall 2018
// Chris Hartman

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iomanip>
using std::setfill;
using std::setw;


// Class Time
// Holds a time of day: hours, minutes, seconds. Can print its stored
// time in a nice format.
class Time {

public:
// ***** Time: constructors *****

	Time(): _hr(0), _min(0), _sec(0) {

	}

	Time(const int hr, const int min, const int sec) : _hr(hr), _min(min), _sec(sec) {
		
	}

// ***** Time: general public member functions *****

    void print() const
    {
		cout << setfill('0') << setw(2) << _hr << ":"
			 << setfill('0') << setw(2) << _min << ":"
			 << setfill('0') << setw(2) << _sec;
    }

// ***** Time: data members *****
private:

    int _hr;   // Hours past midnight
    int _min;  // Minutes past the hour
    int _sec;  // Seconds past the minute

};  // End class Time


int main()
{
    // Print header
    cout << "Here are some times:" << endl;
    cout << endl;

    // Make a Time object; print it
    Time t1;
    cout << "Time #1: [";
    t1.print();
    cout << "]" << endl;
    cout << endl;

	Time t2(9, 39, 23);
	cout << "Time #2: [";
	t2.print();
	cout << "]" << endl;
	cout << endl;

    // Wait for user
    cout << "PRESS ENTER to quit ";
    while (cin.get() != '\n') ;
}

