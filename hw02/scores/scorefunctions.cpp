/*
	scorefunctions.cpp
	Andrew Ng
	Sep 22 2019
	Score function definitions for hw2
*/

#include <iostream>
#include <vector>
#include <string>
#include "scorefunctions.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void InputScores(vector<string>& names, vector<int>& scores, int& numScores)
{
	string name;
	int score;
	cout << "Enter name and score pairs, with no duplicate names (Example: Joe 17)." << endl;
	cout << "Enter 'NoName 0' when you want to stop entering names." << endl;
	while (true) {
		cout << "Please enter a name and score pair: ";
		cin >> name >> score;
		if (name == "NoName" && score == 0) {
			break;
		}
		for (int i = 0; i < numScores; ++i) {
			if (name == names[i]) {
				cout << "ERROR: Duplicate name. Ending program..." << endl;
				exit(1);
			}
		}
		names.push_back(name);
		scores.push_back(score);
		numScores++;
	}
}

void PrintScores(const vector<string>& names, const vector<int>& scores, const int& numScores)
{
	cout << endl << "The scores in this list are: " << endl;
	for (int i = 0; i < numScores; ++i) {
		cout << names[i] << " " << scores[i] << endl;
	}
}

void SearchName(const vector<string>& names, const vector<int>& scores, const int& numScores)
{
	string nameToFind;
	cout << "Enter a name to search: ";
	cin >> nameToFind;
	for (int i = 0; i < numScores; ++i) {
		if (nameToFind == names[i]) {
			cout << endl << "Their score is: " << scores[i] << "." << endl;
			return;
		}
	}
	cout << "Name not found." << endl;
}

void SearchScore(const vector<string>& names, const vector<int>& scores, const int& numScores)
{
	int scoreToFind;
	int scoreFound = 0;
	cout << "Enter a score to search: ";
	cin >> scoreToFind;
	cout << endl;
	for (int i = 0; i < numScores; ++i) {
		if (scoreToFind == scores[i]) {
			cout << names[i] << " has a score of " << scoreToFind << "." << endl;
			scoreFound = 1;
		}
	}
	if (scoreFound == 0) {
		cout << "Name not found." << endl;
	}
}