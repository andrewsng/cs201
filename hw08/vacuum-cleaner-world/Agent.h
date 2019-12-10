/*
Agent.h
Andrew Ng
Dec 9 2019
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
	// constructor defaults to clean room, room 0
	Agent() : dirty_{ 0 }, currentRoom_{ 0 }, option_{ 0 }
	{}

	void perceive(Environment& building);

	void think(Environment& building);

	void instruct(Environment& building);

private:
	bool dirty_;

	size_t currentRoom_;

	int option_;
};

#endif