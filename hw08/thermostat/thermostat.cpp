/*
thermostat.cpp
Andrew Ng
Dec 8 2019
main for thermostat simulator
*/


#include <iostream>
#include "Agent.h"
#include "Environment.h"
#include "Simulator.h"


using std::cin;
using std::cout;
using std::endl;


// Creates new simulator and runs it
int main()
{
	Simulator coolRoomSim;
	coolRoomSim.run();
}