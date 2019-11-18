#include <iostream>
#include <map>
#include <algorithm>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;


int main()
{
	vector<char> answer{ 'h', 'o', 'w', 'd', 'y' };
	map<char, int> letters;
	int wrong = 0;
	while (wrong < 10) {
		char guess;
		cin >> guess;
		if (letters.count(guess) != 0) {
			cout << guess << " was already guessed." << endl;
			continue;
		}
		++letters[guess];
		if (std::find(answer.begin(), answer.end(), guess) == answer.end()) {
			cout << guess << " not found" << endl;
			wrong++;
		}
		else {
			cout << guess << " is correct." << endl;
		}
	}
	for (const auto m : letters) {
		cout << m.first << ' ' << m.second << endl;
	}
}