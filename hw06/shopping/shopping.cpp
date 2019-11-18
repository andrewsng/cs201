/*
shopping.cpp
Andrew Ng
Nov 17 2019
Store program for hw 6
*/


#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;
using std::setw;
using std::setprecision;
using std::fixed;


struct Record
{
	double unitPrice;
	int units;
};


map<string, Record> items{
	{ "Burger", { 15.00, 0 } },
	{ "Hot Dog", { 11.00, 0 } },
	{ "Pizza", { 17.50, 0 } },
	{ "Popcorn", { 25.50, 0 } },
	{ "Soda", { 20.50, 0 } }
};


void addItem(const string& itemName)
{
	int addNum = 0;
	cout << "How many do you want to add?" << endl;
	cin >> addNum;
	items[itemName].units += addNum;
}


void addMenu()
{
	int optionNum = 0;
	while (true) {
		cout << endl << "What would you like to add to your order?\n";
		int opt = 1;
		for (const auto m : items) {
			cout << opt << ") " << "$" << setw(5) << setprecision(2) 
				 << fixed << m.second.unitPrice << " " << m.first << '\n';
			++opt;
		}
		cout << opt << ")  Return" << endl;
		cin >> optionNum;
		switch (optionNum) {
		case 1:
			addItem("Burger");
			continue;
		case 2:
			addItem("Hot Dog");
			continue;
		case 3:
			addItem("Pizza");
			continue;
		case 4:
			addItem("Popcorn");
			continue;
		case 5:
			addItem("Soda");
			continue;
		case 6:
			break;
		default:
			cout << "That's not an available option." << endl;
			continue;
		}
		break;
	}
}


void removeItem(const string& itemName)
{
	int removeNum = 0;
	cout << "How many do you want to remove?" << endl;
	cin >> removeNum;
	items[itemName].units -= removeNum;
}


void removeMenu()
{
	int optionNum = 0;
	while (true) {
		cout << endl << "What would you like to remove from your order?\n";
		int opt = 1;
		for (const auto m : items) {
			cout << opt << ") " << "$" << setw(5) << setprecision(2)
				<< fixed << m.second.unitPrice << " " << m.first << '\n';
			++opt;
		}
		cout << opt << ")  Return" << endl;
		cin >> optionNum;
		switch (optionNum) {
		case 1:
			removeItem("Burger");
			continue;
		case 2:
			removeItem("Hot Dog");
			continue;
		case 3:
			removeItem("Pizza");
			continue;
		case 4:
			removeItem("Popcorn");
			continue;
		case 5:
			removeItem("Soda");
			continue;
		case 6:
			break;
		default:
			cout << "That's not an available option." << endl;
			continue;
		}
		break;
	}
}


void showCart()
{
	vector<double> costs;
	cout << endl << "Your order:" << endl;
	for (const auto m : items) {
		double cost = m.second.unitPrice * m.second.units;
		costs.push_back(cost);
		cout << setw(3) << m.second.units << " " << m.first << endl;
	}
	double sum = std::accumulate(costs.begin(), costs.end(), 0.00);
	cout << endl << "Your total cost:" << endl;
	cout << "$" << setw(5) << setprecision(2) << fixed << sum << endl;
}


int main()
{
	cout << "Welcome to the theater!" << endl;
	int optionNum;
	while (true) {
		cout << endl << "What would you like to do?\n"
			<< "1) Add items to your order\n"
			<< "2) Remove items from your order\n"
			<< "3) See current order\n"
			<< "4) Exit Program" << endl;
		cin >> optionNum;
		switch (optionNum) {
		case 1:
			addMenu();
			continue;
		case 2:
			removeMenu();
			continue;
		case 3:
			showCart();
			continue;
		case 4:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "That's not an available option." << endl;
			continue;
		}
		break;
	}
}