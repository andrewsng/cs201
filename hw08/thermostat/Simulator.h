/*
Simulator.h
Andrew Ng
Dec 8 2019
header for Simulator class
*/


#pragma once

#ifndef SIMULATOR_H
#define SIMULATOR_H


// Simulator class
class Simulator
{
public:
	// constructor defaults to room temp
	Simulator() : targetTemp_{ 68 }
	{}

	void run();

	bool askOwner();

	int getTarget() const;

private:
	int targetTemp_;
};

#endif 