/*
Environment.h
Andrew Ng
Dec 9 2019
header for Environment class
*/


#pragma once

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


#include <vector>


// Environment class
class Environment
{
public:
	// constructor defaults to 2 dirty rooms
	Environment() : rooms_(2, 1), vacuumPos_{ 0 }, action_{ 0 }
	{}

	void iteration();

	void setAction(const int& option);

	size_t getRoom() const;

	std::vector<bool> getRooms() const;

	int getStatus(const size_t& roomNum) const;

	void printEnvironment() const;

	bool checkClean() const;

	void makeRoom();

private:
	std::vector<bool> rooms_;

	size_t vacuumPos_;

	int action_;
};

#endif