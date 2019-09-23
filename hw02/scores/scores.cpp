/*
	scores.cpp
	Andrew Ng
	Sep 22 2019
	Names and scores program for hw2
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

int main()	// Prompts for various name inputs and calls functions
{
	vector<string> names;
	vector<int> scores;
	int numScores = 0;
	InputScores(names, scores, numScores);
	PrintScores(names, scores, numScores);
	int optionNum;
	while (true) {
		cout << endl << "What would you like to do?\n"
			<< "1) Add names and scores\n"
			<< "2) Print list of names and scores\n"
			<< "3) Search for a name\n"
			<< "4) Search for a score\n"
			<< "5) Exit Program" << endl;
		cin >> optionNum;
		switch (optionNum) {
		case 1:
			InputScores(names, scores, numScores);
			continue;
		case 2:
			PrintScores(names, scores, numScores);
			continue;
		case 3:
			SearchName(names, scores, numScores);
			continue;
		case 4:
			SearchScore(names, scores, numScores);
			continue;
		case 5:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "That's not an available option." << endl;
			continue;
		}
		break;
	}
	return 0;
}