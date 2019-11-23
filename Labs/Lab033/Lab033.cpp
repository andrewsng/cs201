/*
Lab033.cpp
Andrew Ng
Nov 20 2019
Lab 33 for cs201
*/


#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::to_string;


class Neat
{
public:
	void print() {
		cout << "Hello" << endl;
	}
	void setNum(int newNum) {
		num_ = newNum;
	}
	int getNum() {
		return num_;
	}
	void setStr(string newStr) {
		str_ = newStr;
	}
	string getStr() {
		return str_;
	}
	void toString() {
		printed_ = to_string(num_) + ", " + str_;
		cout << printed_ << endl;
	}
private:
	int num_ = 0;
	string str_;
	string printed_;
};


int main()
{
	Neat obj1;
	Neat obj2;

	obj1.setNum(3);
	obj1.setStr("hello");

	obj2.setNum(5);
	obj2.setStr("howdy");

	obj1.toString();
	obj2.toString();
}