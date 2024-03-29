/*
	birthday.cpp
	Andrew Ng
	4 Sep 2019
	Birthday program for lab 02
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int month, day, year;
	cout << "Enter the month of your birthday as an integer." << endl;
	cin >> month;
	cout << "Enter the day of your birthday as an integer." << endl;
	cin >> day;
	cout << "Enter the year of your birthday as an integer." << endl;
	cin >> year;
	cout << "Your birthday is: " << year << "-";
	if (month < 10) {
		cout << "0" << month << "-";
	}
	else {
		cout << month << "-";
	}
	if (day < 10) {
		cout << "0" << day << endl;
	}
	else {
		cout << day << endl;
	}
	return 0;
}

/*
PART 1
--------------------
int main()
{
	int month, day, year;
	cout << "Enter the month of your birthday as an integer." << endl;
	cin >> month;
	cout << "Enter the day of your birthday as an integer." << endl;
	cin >> day;
	cout << "Enter the year of your birthday as an integer." << endl;
	cin >> year;
	cout << "Your birthday is: " << month << "/" << day << "/" << year << endl;
	return 0;
}
*/