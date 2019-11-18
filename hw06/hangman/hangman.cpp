#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;


int main()
{
	vector<char> answer{ 'h', 'o', 'w', 'd', 'y' };
	std::unique(answer.begin(), answer.end());
	std::for_each(answer.begin(), answer.end(),
		[](char& c) {
			c = std::toupper(c);
		});
	map<char, int> letters;
	int wrong = 0;
	while (wrong <= 10) {
		if (wrong == 10) {
			cout << '\n' << "You lose!" << endl;
			break;
		}
		char guess;
		cin >> guess;
		guess = std::toupper(guess);
		if (letters.count(guess) != 0) {
			cout << guess << " was already guessed." << endl;
			cout << "You have " << 10 - wrong << " more guesses." << endl;
			continue;
		}
		++letters[guess];
		auto findIter = std::find(answer.begin(), answer.end(), guess);
		if (findIter == answer.end()) {
			cout << guess << " is not in the word." << endl;
			wrong++;
			cout << "You have " << 10 - wrong << " more guesses." << endl;
		}
		else {
			cout << guess << " is correct." << endl;
			answer.erase(findIter);
		}
		if (answer.empty() == 1) {
			cout << '\n' << "You win!" << endl;
			break;
		}
	}
}