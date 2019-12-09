/*
Environment.cpp
Andrew Ng
Dec 8 2019
source code for Environment class
*/


#include "Environment.h"
#include <iostream>


// Raises/lowers temp based on heater setting
void Environment::iteration() {
	if (heater_) {
		std::cout << "Raising temperature by 1 degree... ";
		temperature_++;
	}
	else {
		std::cout << "Lowering temperature by 1 degree... ";
		temperature_--;
	}
	std::cout << "New temp: " << temperature_ << std::endl;
}


// Returns current temp
int Environment::getTemp() const {
	return temperature_;
}


// Sets heater option to given number
void Environment::setHeater(const bool& option) {
	heater_ = option;
}