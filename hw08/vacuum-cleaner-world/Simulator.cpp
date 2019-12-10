/*
Simulator.cpp
Andrew Ng
Dec 9 2019
source code for Simulator class
*/


#include "Simulator.h"
#include "Environment.h"
#include "Agent.h"
#include <iostream>
#include <string>
#include <sstream>


// Runs simulation by looping through functions
void Simulator::run() {
	Environment building;
	Agent vacuum;
	std::cout << "----------------------\n";
	std::cout << "-- Vacuum Simulator --\n";
	std::cout << "----------------------" << std::endl;
	while (true) {
		building.printEnvironment();
		if (building.checkClean()) {
			std::cout << "\nAll rooms are clean. Ending program...";
			std::cout << std::endl;
			break;
		}
		vacuum.perceive(building);
		vacuum.think(building);
		vacuum.instruct(building);
		building.iteration();
		building.makeRoom();
	}
}