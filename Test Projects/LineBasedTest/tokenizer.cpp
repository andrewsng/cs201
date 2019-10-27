/*
	tokenizer.cpp
	Andrew Ng
	Oct 15 2019
	source for string/token functions for hw 4
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include "tokenizer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;
using std::vector;


// puts line received from user into referenced string
bool ReadLine(string& str)
{
	std::getline(cin, str);

	// returns false if string is empty
	if (str.empty()) {
		return false;
	}
	else {
		return true;
	}
}

// 15 + 4(20^2) * -9.3
// separates strings by whitespace, pushes strings into a vector
unsigned StringToTokensWS(vector<string>& tokens, string& str)
{
	istringstream instream(str);
	string strToPush;
	string empty;
	unsigned tokenCounter = 1;
	for (size_t i = 0; i < str.size(); ++i) {
		for (size_t j = i; j <= str.size(); ++j) {
			if (isdigit(str[i]) && !isdigit(str[j])) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
			}
			if (isalpha(str[i]) && !isalpha(str[j])) {
				tokens.push_back(str.substr(i, j - i));
				i = j;
			}
			if (ispunct(str[i])) {
				tokens.push_back(str.substr(i, 1));
				++i;
			}
		}
	}
	AnalyzeTokens(tokens);
	/*
	while (true) {
		instream >> strToPush;
		if (instream) {
			tokens.push_back(strToPush);
			tokenCounter++;
		}
		else {
			break;
		}
	}
	tokens.push_back(empty);
	*/

	// returns number of tokens pushed
	return tokenCounter;
}


// performs various checks on tokens, prints them with determined type of token
void AnalyzeTokens(const vector<string>& tokens)
{
	for (const auto& s : tokens) {

		// whitespace: if empty string
		if (s.empty()) {
			cout << "[whitespace]\t" << "\"" << s << "\"" << endl;
			continue;
		}

		// integer: if all characters are digits
		for (int i = 0; i < s.size(); ++i) {
			if (!isdigit(s[i])) {
				break;
			}
			if (i == s.size() - 1) {
				cout << "[integer]\t" << "\"" << s << "\"" << endl;
				goto determined;
			}
		}

		// string: if starts and ends with double quote
		if (s.front() == '"' && s.back() == '"' && s.size() > 2) {
			cout << "[string]\t" << "\"\\"
				 << s.substr(0, s.size() - 1) << "\\\"\"" << endl;
			continue;
		}

		// identifier: if first char is a letter or underscore, and
		// characters beyond that are alphanumerical or underscores
		for (int j = 0; j < s.size(); ++j) {
			if (!isalpha(s[0]) && s[0] != '_') {
				break;
			}
			if (!isalnum(s[j]) && s[j] != '_') {
				break;
			}
			if (j == s.size() - 1) {
				cout << "[identifier]\t" << "\"" << s << "\"" << endl;
				goto determined;
			}
		}

		// other: if single character that is considered punctuation
		if (s.size() == 1 && ispunct(s[0])) {
			cout << "[other]\t\t" << "\"" << s << "\"" << endl;
			continue;
		}

		// unknown: if none of the others are met
		cout << "[unknown]\t" << "\"" << s << "\"" << endl;

	// goto statement label for continuing from nested for-loops
	determined:;
	}
}