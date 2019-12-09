/*
Simulator.cpp
Andrew Ng
Dec 8 2019
source code for Simulator class
*/


#include "Simulator.h"
#include "Environment.h"
#include "Agent.h"
#include <iostream>
#include <string>
#include <sstream>


// Runs simulation by looping through functions
void Simulator::run() {
	Environment room;
	Agent thermostat;
	std::cout << "--------------------------\n";
	std::cout << "-- Thermostat Simulator --\n";
	std::cout << "--------------------------" << std::endl;
	while (true) {
		std::cout << "\nThe current temperature is: ";
		std::cout << room.getTemp() << " degrees F" << std::endl;
		if (!askOwner()) {
			break;
		}
		for (int i = 0; i < 10; ++i) {
			thermostat.perceive(room);
			thermostat.think(*this);
			thermostat.act(room);
			room.iteration();
		}
	}
}


// Sets target temp or exits program based on input
bool Simulator::askOwner() {
	std::string str;
	int target;
	while (true) {
		std::cout << "\nEnter the target temperature for the thermostat.\n";
		std::cout << "Enter \"quit\" to end the program." << std::endl;
		std::getline(std::cin, str);
		if (str == "quit") {
			std::cout << "Exiting program..." << std::endl;
			return false;
		}
		std::istringstream iss(str);
		iss >> target;
		if (!iss) {
			std::cout << "Input was not an integer. Try again." << std::endl;
			iss.clear();
			iss.ignore(999999, '\n');
			continue;
		}
		break;
	}
	targetTemp_ = target;
	return true;
}


// Returns stored target temperature
int Simulator::getTarget() const {
	return targetTemp_;
}