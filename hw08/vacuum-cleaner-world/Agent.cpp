/*
Agent.cpp
Andrew Ng
Dec 9 2019
source code for Agent class
*/


#include "Agent.h"
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>


// Gets current room index
// Gets current clean/dirty status
void Agent::perceive(Environment& building) {
	currentRoom_ = building.getRoom();
	dirty_ = building.getStatus(currentRoom_);
}


// If room is dirty, option 0 (clean)
// If dirty room is closer to left, option 1 (move left)
// If dirty room is closer to right, option 2 (move right)
// If neither direction is closer, rand between 1 and 2
void Agent::think(Environment& building) {
	if (dirty_) {
		option_ = 0;
	}
	else {
		std::vector<bool> rooms = building.getRooms();
		int rightDist = INT_MAX;
		int leftDist = INT_MAX;
		auto rightIt = std::find(rooms.begin() 
			+ currentRoom_, rooms.end(), 1);
		auto leftIt = std::find(rooms.rbegin() 
			+ (rooms.size() - currentRoom_ - 1), rooms.rend(), 1);
		if (rightIt != rooms.end()) {
			rightDist = rightIt - (rooms.begin() + currentRoom_);
			std::cout << "Dirty room " << rightDist
					<< " room(s) to right" << std::endl;
		}
		if (leftIt != rooms.rend()) {
			leftDist = leftIt - (rooms.rbegin() + (rooms.size() - currentRoom_ - 1));
			std::cout << "Dirty room " << leftDist
					<< " room(s) to left" << std::endl;
		}
		if (leftDist < rightDist) {
			option_ = 1;
		}
		else if (leftDist > rightDist) {
			option_ = 2;
		}
		else {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> distrib(1, 2);
			option_ = distrib(gen);
		}
	}
}


// Passes the chosen option to an Environment's stored action
void Agent::instruct(Environment& building) {
	building.setAction(option_);
}