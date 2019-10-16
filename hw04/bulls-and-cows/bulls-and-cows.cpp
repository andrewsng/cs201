#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void takeGuess(vector<int>& guess)
{
	string number;
	int pushed;
	while (true) {
		guess.clear();
		cin >> number;
		for (int i = 0; i < number.size(); ++i) {
			if (number[i] < '0' || number[i] > '9' || number.size() != 4) {
				cout << "You did not enter a 4 digit number. Try again." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			string digit(1, number[i]);
			std::istringstream instream(digit);
			instream >> pushed;
			guess.push_back(pushed);
		}
		if (guess.size() == 4) {
			break;
		}
	}
}

int bulls(const vector<int>& answer, const vector<int>& guess)
{
	return 0;
}

int main()
{
	vector<int> answer{ 1, 2, 3, 4 };
	vector<int> guess;
	while (true) {
		takeGuess(guess);
		cout << "vector is" << endl;
		for (auto i : guess) {
			cout << i << endl;
		}
	}
}