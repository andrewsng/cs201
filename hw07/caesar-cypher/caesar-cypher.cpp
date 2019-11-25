/*
caesar-cypher.cpp
Andrew Ng
Nov 25 2019
Caesar Cypher program
for hw7
*/


#include <iostream>
#include <string>
#include <cctype>
#include <sstream>


using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::string;


int main()
{
	cout << "Caesar Cypher\n" << endl;
	while (true) {

		// string message input
		string msg;
		cout << "Enter a message to cypher (blank line to end): ";
		getline(cin, msg);

		// quit program
		if (msg.empty()) {
			cout << endl << "Program Complete" << endl;
			return 0;
		}

		// shift integer input
		int shift;
		while (true) {
			string numStr;
			cout << "Enter an integer to use as the shift: ";
			cin >> numStr;
			std::istringstream iss(numStr);
			iss >> shift;
			if (!iss) {
				cout << "ERROR: Try again." << endl;
				cin.clear();
				cin.ignore(999999, '\n');
				continue;
			}
			break;
		}
		cout << endl;

		shift = shift % 26;
		for (size_t i = 0; i < msg.size(); ++i) {

			// dealing with uppercase and out of bounds
			if (isalpha(msg[i]) && isupper(msg[i])) {
				if (msg[i] + shift > 90) {
					msg[i] = shift - 26 + msg[i];
				}
				else if (msg[i] + shift < 65) {
					msg[i] = shift + 26 + msg[i];
				}
				else {
					msg[i] = msg[i] + shift;
				}
			}

			// dealing with lowercase and out of bounds
			if (isalpha(msg[i]) && islower(msg[i])) {
				if (msg[i] + shift > 122) {
					msg[i] = shift - 26 + msg[i];
				}
				else if (msg[i] + shift < 97) {
					msg[i] = shift + 26 + msg[i];
				}
				else {
					msg[i] = msg[i] + shift;
				}
			}
		}

		// output result
		cout << "Result: " << msg << endl << endl;

		// clear cin buffer
		cin.clear();
		cin.ignore(999999, '\n');
	}
}