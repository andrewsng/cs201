/*
vacuum-cleaner-world.cpp
Andrew Ng
Dec 9 2019
main for vacuum cleaner simulator
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
	Simulator coolVacuumSim;
	coolVacuumSim.run();
}