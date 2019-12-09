#include "Simulator.h"
#include "Environment.h"
#include "Agent.h"
#include <iostream>
#include <string>
#include <sstream>


void Simulator::run() {
	Environment room;
	Agent thermostat;
	while (true) {
		if (!askOwner()) {
			break;
		}
		for (int i = 0; i < 10; ++i) {
			room.iteration();
			std::cout << "it" << std::endl;
			thermostat.perceive(room);
			std::cout << "perceive" << std::endl;
			thermostat.think(*this);
			std::cout << "think" << std::endl;
			thermostat.act(room);
			std::cout << "act" << std::endl;
		}
	}
}


bool Simulator::askOwner() {
	std::string str;
	std::istringstream iss(str);
	int target;
	while (true) {
		std::getline(std::cin, str);
		if (str == "quit") {
			return false;
		}
		iss >> target;
		if (!iss) {
			iss.clear();
			iss.ignore(999999, '\n');
			continue;
		}
		break;
	}
	targetTemp_ = target;
	return true;
}


int Simulator::getTarget() const {
	return targetTemp_;
}