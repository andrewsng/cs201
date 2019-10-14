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
		cout << StringToTokensWS(tokens, str) << " tokens" << endl;
		for (auto s : tokens) {
			cout << s << endl;
		}
		if (str == "end") {
			tokens.pop_back();
			cout << tokens.size() << endl;
			break;
		}
	}
	AnalyzeTokens(tokens);
}