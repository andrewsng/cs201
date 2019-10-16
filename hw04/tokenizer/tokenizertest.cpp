#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "tokenizer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	string str;
	vector<string> tokens;
	while (true) {
		ReadLine(str);
		StringToTokensWS(tokens, str);
		if (tokens[tokens.size() - 2] == "end" ||
			tokens[tokens.size() - 2] == "End" || 
			tokens[tokens.size() - 2] == "END") {
			tokens.pop_back();
			break;
		}
	}
	AnalyzeTokens(tokens);
}