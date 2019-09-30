/**
 * @file     userInputMain.cpp
 * @author   Student Name
 * @version  Jan 21, 2019
 * John Quan
 * @brief    Print out every word that was entered
 *
 * Input an arbitrary number of “words” from the user (ending
 * when the user types some special word: perhaps something like
 * “end”). After all the input is done, the program should print
 * out every word that was entered separated by a space.
 */

#include "userInput.hpp"
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::vector<std::string> words;

	// prompt
	std::cout << "Enter a series of strings (type \"end\" to finish): "
			<< std::endl;
	// TODO create userInput.cpp with this function
	getUserStrings(words);

	std::cout << std::endl;
	std::cout << "----------------------Required--------------------------"
			<< std::endl;
	// print all words
	for (unsigned long i = 0; i < words.size(); ++i) {
		std::cout << words[i] << ' ';
	}

	std::cout << std::endl;
	std::cout << "----------------------Additional 1----------------------"
			<< std::endl;
	// TODO print only words >= 5
	for (unsigned long i = 0; i < words.size(); ++i) {
		if (words[i].size() >= 5) {
			std::cout << words[i] << ' ';
		}
	}

	char c = 'x';
	std::cout << std::endl;
	std::cout << "----------------------Additional 2----------------------"
			<< std::endl;
	// TODO print only words containing char c
	for (unsigned long i = 0; i < words.size(); ++i) {
		if (hasChar(words[i], 'x') || hasChar(words[i], 'X')) {
			std::cout << words[i] << ' ';
		}
	}

	return 0;
}
