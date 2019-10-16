/*
	bulls-and-cows.cpp
	Andrew Ng
	Oct 15 2019
	bulls and cows guessing game for hw 4
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


void takeGuess(vector<int>& guess)
{
	// takes number as a string
	string number;
	int pushed;
	while (true) {
		guess.clear();
		cin >> number;
		for (int i = 0; i < number.size(); ++i) {

			// if character isn't a number, or if size isn't 4 digits, reset input
			if (number[i] < '0' || number[i] > '9' || number.size() != 4) {
				cout << "You did not enter a 4 digit number. Try again." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

			// make a string holding just one digit
			// put digit in an int, push int into vector
			string digit(1, number[i]);
			std::istringstream instream(digit);
			instream >> pushed;
			guess.push_back(pushed);
		}

		// success if vector makes it to 4 digits
		if (guess.size() == 4) {
			break;
		}
	}
}

int bulls(const vector<int>& answer, const vector<int>& guess)
{
	int numBulls = 0;
	for (int i = 0; i < 4; ++i) {
		if (guess[i] == answer[i]) {
			numBulls++;
		}
	}
	return numBulls;
}

int cows(const vector<int>& answer, const vector<int>& guess)
{
	int numCows = 0;
	if (guess[0] == answer[1] || guess[0] == answer[2] || guess[0] == answer[3]) {
		numCows++;
	}
	if (guess[1] == answer[0] || guess[1] == answer[2] || guess[1] == answer[3]) {
		numCows++;
	}
	if (guess[2] == answer[0] || guess[2] == answer[1] || guess[2] == answer[3]) {
		numCows++;
	}
	if (guess[3] == answer[0] || guess[3] == answer[1] || guess[3] == answer[2]) {
		numCows++;
	}
	return numCows;
}

int main()
{
	cout << "Guess a number of 4 different digits!" << endl;
	cout << "A bull means a digit is right and in the right position." << endl;
	cout << "A cow means a digit is right but in the wrong position." << endl;
	vector<int> answer{ 3, 4, 6, 1 };
	vector<int> guess;
	while (true) {
		takeGuess(guess);
		if (bulls(answer, guess) == 4) {
			cout << "You won!" << endl;
			break;
		}
		cout << bulls(answer, guess) << " bulls, and "
			<< cows(answer, guess) << " cows" << endl;
	}
}