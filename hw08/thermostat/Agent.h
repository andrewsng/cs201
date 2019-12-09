/*
Agent.h
Andrew Ng
Dec 8 2019
header for Agent class
*/


#pragma once

#ifndef AGENT_H
#define AGENT_H


#include "Environment.h"
#include "Simulator.h"


// Agent class
class Agent
{
public:
	// constructor defaults to heater off, room temp
	Agent() : currentTemp_{ 68 }, heaterOpt_{ 0 }
	{}

	void perceive(Environment& room);

	void think(Simulator& roomSim);

	void act(Environment& room);

private:
	int currentTemp_;
	bool heaterOpt_;
};

#endif