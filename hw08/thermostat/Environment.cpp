#include "Environment.h"
#include <iostream>


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


int Environment::getTemp() const {
	return temperature_;
}


void Environment::setHeater(const bool& option) {
	heater_ = option;
}