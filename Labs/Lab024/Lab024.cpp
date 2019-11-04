#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void printVec(const vector<int>& numbers)
{
	for (const auto& i : numbers) {
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> numbers{ 126, 23, 86, 16, 9, 209, 13, 63, 41, 6 };
	int start;
	int end;
	printVec(numbers);
	cout << "Enter 2 indices within 0 and 10" << endl;
	cin >> start >> end;
	cout << endl;
	cout << "Sorting the vector: " << endl;
	std::sort(numbers.begin()+start, numbers.begin()+end);
	printVec(numbers);
	cout << "Reversing the vector: " << endl;
	std::reverse(numbers.begin() + start, numbers.begin() + end);
	printVec(numbers);
	cout << "Filling the vector: " << endl;
	std::fill(numbers.begin() + start, numbers.begin() + end, 11);
	printVec(numbers);

}