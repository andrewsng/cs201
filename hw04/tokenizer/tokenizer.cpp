#include <iostream>
#include <string>
#include <sstream>
#include <vector>
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
	while (true) {
		instream >> strToPush;
		if (instream) {
			tokens.push_back(strToPush);
		}
		else {
			break;
		}
	}
	tokens.push_back(empty);
	return tokens.size();
}

void AnalyzeTokens(const vector<string>& tokens)
{

}