/*
hangman.cpp
Andrew Ng
Dec 9 2019
Refined hangman game for hw 8
*/


#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;


// Allows user to input a new answer
void changeAnswer(string& answer) {
	while (true) {
		cout << "Enter a new word to use as the answer." << endl;
		string newAnswer;
		cin >> newAnswer;

		// Error check
		bool badStr = 0;
		for (auto c : newAnswer) {
			if (!isalpha(c)) {
				badStr = 1;
				break;
			}
		}
		if (badStr) {
			cout << "ERROR: Answer must be only letters." << endl;
			cin.clear();
			cin.ignore(999999, '\n');
			continue;
		}

		// Make string uppercase and set answer
		std::for_each(newAnswer.begin(), newAnswer.end(),
			[](char& c) {
				c = std::toupper(c);
			});
		answer = newAnswer;

		// "Clear" command prompt screen
		cout << string(1000, '\n');
		break;
	}
}


// Runs the game with a given answer
void playGame(string& answer) {
	// Instructions
	cout << "Hangman!" << '\n';
	cout << "Enter letters to guess the word." << '\n';
	cout << "10 wrong letters and you lose!" << endl;

	// Copy of original answer
	string ansCopy = answer;
	// Remove duplicate characters from string
	auto last = std::unique(answer.begin(), answer.end());
	answer.erase(last, answer.end());
	// Empty lines to put correct letters into
	string correct(ansCopy.size(), '_');

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
		cin.clear();
		cin.ignore(999999, '\n');

		// Checks if not a letter
		if (!isalpha(guess)) {
			cout << guess << " is not a letter." << endl;
			cout << "You have " << 10 - wrong << " more guesses." << endl;
			continue;
		}

		// Repeat answer check
		if (letters.count(guess) != 0) {
			cout << guess << " was already guessed." << endl;
			cout << "You have " << 10 - wrong << " more guesses." << endl;
			continue;
		}

		// Records guessed letters
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
			while (true) {
				// Erase all instances of the correct letter
				auto eraseIt = std::find(answer.begin(), answer.end(), guess);
				if (eraseIt != answer.end()) {
					answer.erase(eraseIt);
				}
				else {
					break;
				}
			}

			// Reveal correct letters on blank lines
			for (int i = 0; i < correct.size(); ++i) {
				if (ansCopy[i] == guess) {
					correct[i] = ansCopy[i];
				}
			}
			cout << endl;
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


// Contains menu options
int main()
{
	cout << "Welcome to Hangman!" << '\n';

	int optionNum;
	// Boring default answer
	string answer = "BORING";
	while (true) {
		string tempAnswer = answer;
		cout << endl << "What would you like to do?\n"
			<< "1) Change the answer\n"
			<< "2) Play game\n"
			<< "3) Exit Program" << endl;
		cin >> optionNum;
		switch (optionNum) {
		case 1:
			changeAnswer(answer);
			continue;
		case 2:
			playGame(answer);
			answer = tempAnswer;
			continue;
		case 3:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "That's not an available option." << endl;
			cin.clear();
			cin.ignore(999999, '\n');
			continue;
		}
		break;
	}
}