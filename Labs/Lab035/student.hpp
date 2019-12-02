/*
student.hpp
Andrew Ng
Nov 25 2019
header for class declaration
for lab 35
*/


#pragma once

#ifndef STUDENT_HPP
#define STUDENT_HPP


#include <string>


class Student {
public:
	Student() : name_("Unknown"), id_(0)
	{}
	Student(const std::string& str) : name_(str), id_(9999)
	{}
	Student(const std::string& str, const int& num)
		: name_(str), id_(num)
	{}

	void printInfo() const;

private:
	std::string name_;
	int id_;
};


#endif