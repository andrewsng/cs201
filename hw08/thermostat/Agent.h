#pragma once
#include "Environment.h"
#include "Simulator.h"


class Agent
{
public:
	Agent() : currentTemp_{ 0 }, heaterOpt_{ 0 }
	{}

	void perceive(Environment& room);

	void think(Simulator& roomSim);

	void act(Environment& room);

private:
	int currentTemp_;
	bool heaterOpt_;
};