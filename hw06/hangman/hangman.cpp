/*
hangman.cpp
Andrew Ng
Nov 17 2019
Hangman game for hw 6
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;


int main()
{
	cout << "Hangman!" << '\n';
	cout << "Enter letters to guess the word." << '\n';
	cout << "10 wrong letters and you lose!" << endl;

	// Defining vector containing answer
	// Make all characters uppercase
	vector<char> answer{ 'h', 'o', 'w', 'd', 'y' };
	std::for_each(answer.begin(), answer.end(),
		[](char& c) {
			c = std::toupper(c);
		});
	// Copy of original answer
	vector<char> ansCopy = answer;
	// Remove duplicate characters from vector
	auto last = std::unique(answer.begin(), answer.end());
	answer.erase(last, answer.end());
	// Empty lines to put correct letters into
	vector<char> correct(ansCopy.size(), '_');

	map<char, int> letters;
	// Wrong answer counter
	int wrong = 0;
	while (wrong <= 10) {
		// Show correct letters
		for (const auto c : correct) {
			cout << c;
		}
		cout << endl;

		// Lose condition
		if (wrong == 10) {
			cout << '\n' << "You lose!" << endl;
			break;
		}

		// Input char as uppercase
		char guess;
		cin >> guess;
		guess = std::toupper(guess);

		// Repeat answer check
		if (letters.count(guess) != 0) {
			cout << guess << " was already guessed." << endl;
			cout << "You have " << 10 - wrong << " more guesses." << endl;
			continue;
		}

		++letters[guess];
		auto findIter = std::find(answer.begin(), answer.end(), guess);

		// If character was not found in answer
		if (findIter == answer.end()) {
			cout << guess << " is not in the word." << endl;
			wrong++;
			cout << "You have " << 10 - wrong << " more guesses." << endl;
		}
		else {
			cout << guess << " is correct." << endl;
			answer.erase(findIter);

			// Reveal correct letters on blank lines
			for (int i = 0; i < correct.size(); ++i) {
				if (ansCopy[i] == guess) {
					correct[i] = ansCopy[i];
				}
			}
		}

		// Win condition
		if (answer.empty() == 1) {
			cout << '\n' << "You win!" << endl;
			break;
		}
	}

	// Answer reveal
	cout << "The word was: ";
	for (const auto a : ansCopy) {
		cout << a;
	}
	cout << endl;
}