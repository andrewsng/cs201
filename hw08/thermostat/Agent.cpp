/*
Agent.cpp
Andrew Ng
Dec 8 2019
source code for Agent class
*/


#include "Agent.h"


// Gets current temperature from an Environment
void Agent::perceive(Environment& room) {
	currentTemp_ = room.getTemp();
}


// Gets target temperature from a Simulator
// Chooses heater option by comparing target temp to current
void Agent::think(Simulator& roomSim) {
	int target = roomSim.getTarget();
	if (currentTemp_ < target) {
		heaterOpt_ = 1;
	}
	else {
		heaterOpt_ = 0;
	}
}


// Sets an Environment's heater to option previously chosen
void Agent::act(Environment& room) {
	room.setHeater(heaterOpt_);
}