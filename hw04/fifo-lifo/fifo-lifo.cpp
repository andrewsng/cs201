/*
	fifo-lifo.cpp
	Andrew Ng
	Oct 15 2019
	FIFO LIFO demonstration program for hw 4
*/

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void FifoPush(vector<string>& container, const string& item)
{
	container.push_back(item);
}

void FifoPop(vector<string>& container, const string& item)
{
	container.erase(container.begin());
}

void LifoPush(vector<string>& container, const string& item)
{
	container.push_back(item);
}

void LifoPop(vector<string>& container, const string& item)
{
	container.pop_back();
}

bool IsContainerEmpty(const vector<string>& container)
{
	return container.empty();
}

void PrintContainer(const vector<string>& container)
{
	for (const auto& s : container) {
		cout << s << endl;
	}
}

bool TestFifo()
{
	cout << "Testing FIFO..." << endl;
	vector<string> FifoTest;
	for (int i = 0; i < 10; ++i) {
		string pushed(1, 65 + i);
		FifoPush(FifoTest, pushed);
	}
	string saveLast = FifoTest[9];
	cout << "FIFO after 10 pushes:" << endl;
	PrintContainer(FifoTest);
	cout << "Last item in is: " << saveLast << endl;
	for (int j = 0; j < 9; ++j) {
		string pop;
		FifoPop(FifoTest, pop);
	}
	cout << "FIFO after 9 pops:" << endl;
	PrintContainer(FifoTest);
	cout << "Last item to be popped: " << FifoTest[0] << endl;
	if (FifoTest[0] == saveLast) {
		return true;
	}
}

bool TestLifo()
{
	cout << "Testing LIFO..." << endl;
	vector<string> LifoTest;
	for (int i = 0; i < 10; ++i) {
		string pushed(1, 65 + i);
		LifoPush(LifoTest, pushed);
	}
	string saveFirst = LifoTest[0];
	cout << "LIFO after 10 pushes:" << endl;
	PrintContainer(LifoTest);
	cout << "First item in is: " << saveFirst << endl;
	for (int j = 0; j < 9; ++j) {
		string pop;
		LifoPop(LifoTest, pop);
	}
	cout << "LIFO after 9 pops:" << endl;
	PrintContainer(LifoTest);
	cout << "Last item to be popped: " << LifoTest[0] << endl;
	if (LifoTest[0] == saveFirst) {
		return true;
	}
}

int main()
{
	int option;
	vector<string> FifoContainer;
	vector<string> LifoContainer;
	string input;
	while (true) {
		cout << endl << "What would you like to do?\n"
			<< "1) Add item to FIFO\n"
			<< "2) Remove item from FIFO\n"
			<< "3) Add item to LIFO\n"
			<< "4) Remove item from LIFO\n"
			<< "5) Print FIFO\n"
			<< "6) Print LIFO\n"
			<< "7) Test FIFO\n"
			<< "8) Test LIFO\n"
			<< "9) Exit Program" << endl;
		cin >> option;
		switch (option) {
		case 1:
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(cin, input);
			FifoPush(FifoContainer, input);
			continue;
		case 2:
			if (IsContainerEmpty(FifoContainer)) {
				continue;
			}
			FifoPop(FifoContainer, input);
			continue;
		case 3:
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(cin, input);
			LifoPush(LifoContainer, input);
			continue;
		case 4:
			if (IsContainerEmpty(LifoContainer)) {
				continue;
			}
			LifoPop(LifoContainer, input);
			continue;
		case 5:
			PrintContainer(FifoContainer);
			continue;
		case 6:
			PrintContainer(LifoContainer);
			continue;
		case 7:
			if (TestFifo()) {
				cout << "FIFO worked." << endl;
			}
			continue;
		case 8:
			if (TestLifo()) {
				cout << "LIFO worked." << endl;
			}
		case 9:
			break;
		default:
			cout << "That's not an available option." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}
}