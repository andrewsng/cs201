#include "Agent.h"


void Agent::perceive(Environment& room) {
	currentTemp_ = room.getTemp();
}

void Agent::think(Simulator& roomSim) {
	int target = roomSim.getTarget();
	if (currentTemp_ < target) {
		heaterOpt_ = 1;
	}
	else {
		heaterOpt_ = 0;
	}
}

void Agent::act(Environment& room) {
	room.setHeater(heaterOpt_);
}