/*
	diamond.cpp
	Andrew Ng
	Sep 15 2019
	Printing diamond program for hw1
*/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int diamondSize;
	int numColumns;
	cout << "Please enter a positive integer!:" << endl;
	while (true) {
		cin >> diamondSize;
		if (cin.fail() || diamondSize <= 0) {									//checks if cin fails or is 0 or negative
			std::cerr << "ERROR: Input is not a positive integer." << endl;		//outputs error
			cin.clear();														//clears failed state of the input stream
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//discards all characters in input
			continue;
		}
		break;
	}
	numColumns = (diamondSize * 2) - 1;
	for (int i = -(diamondSize - 1); i < diamondSize; i++) {	//setting up equally negative and positive bounds for absolute value
		for (int j = 0; j < abs(i); j++) {
			cout << " ";
		}
		for (int k = 0; k < numColumns - (2*abs(i)); k++) {
			cout << "#";
		}
		cout << endl;
	}
	return 0;
}
