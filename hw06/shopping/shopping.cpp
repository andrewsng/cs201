#include <iostream>
#include <algorithm>
#include <map>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;


struct Record
{
	double unitPrice;
	int units;
};


int main()
{
	int optionNum;
	while (true) {
		cout << endl << "What would you like to do?\n"
			<< "1) Add items to your cart\n"
			<< "2) Remove items from your cart\n"
			<< "3) See current shopping cart\n"
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