#pragma once
#include "Environment.h"
#include "Simulator.h"


class Agent
{
public:
	void perceive(Environment& room);

	void think(Simulator& roomSim);

	void act(Environment& room);

private:
	int currentTemp_;
	bool heaterOpt_;
};