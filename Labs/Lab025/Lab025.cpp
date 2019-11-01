/*
	Lab025.cpp
	Andrew Ng
	Nov 1 2019
	Lab 25 for cs201
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using std::cout;
using std::endl;
using std::vector;
using std::mismatch;
using std::pair;

void printVec(const vector<int>& list)
{
	for (const auto& n : list) {
		cout << n << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> list1{ 6, 3, 8, 4, 1, 3, 7 };
	vector<int> list2{ 6, 3, 8, 4, 5, 3, 5 };
	//vector<int> list2{ 6, 3, 8, 4, 1, 3, 7 };
	printVec(list1);
	printVec(list2);
	while (true) {
		pair<vector<int>::iterator, vector<int>::iterator> p = mismatch(list1.begin(), list1.end(), list2.begin());
		if (p.first == list1.end()) {
			cout << "There are no mismatches!" << endl;
			break;
		}
		else {
			cout << "Mismatch at values " << *p.first << " and " << *p.second << endl;
			*p.second = *p.first;
			printVec(list1);
			printVec(list2);
		}
	}
	return 0;
}