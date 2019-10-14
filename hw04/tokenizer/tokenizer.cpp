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

unsigned StringToTokensWS(vector<string>& tokens)
{
	return 0;
}

void AnalyzeTokens(const vector<string>& tokens)
{

}