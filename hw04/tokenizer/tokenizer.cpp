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

bool ReadLine(string& str)
{
	std::getline(cin, str);
	if (str.empty()) {
		return false;
	}
	else {
		return true;
	}
}

unsigned StringToTokensWS(vector<string>& tokens, string& str)
{
	istringstream instream(str);
	string strToPush;
	string empty;
	int tokenCounter = 1;
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
	return tokenCounter;
}

void AnalyzeTokens(const vector<string>& tokens)
{
	for (const auto& s : tokens) {
		if (s.empty()) {
			cout << "[whitespace]\t" << "\"" << s << "\"" << endl;
			continue;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (!isdigit(s[i])) {
				break;
			}
			if (i == s.size() - 1) {
				cout << "[integer]\t" << "\"" << s << "\"" << endl;
				goto determined;
			}
		}
		if (s.front() == '"' && s.back() == '"' && s.size() > 2) {
			cout << "[string]\t" << "\"\\" << s.substr(0, s.size() - 1) << "\\\"\"" << endl;
			continue;
		}
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
		if (s.size() == 1 && ispunct(s[0])) {
			cout << "[other]\t\t" << "\"" << s << "\"" << endl;
			continue;
		}
		cout << "[unknown]\t" << "\"" << s << "\"" << endl;
	determined:;
	}
}