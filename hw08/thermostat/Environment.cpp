#include "Environment.h"
#include <iostream>


void Environment::iteration() {
	if (heater_) {
		temperature_++;
	}
	else {
		temperature_--;
	}
	std::cout << temperature_ << std::endl;
}


int Environment::getTemp() const {
	return temperature_;
}


void Environment::setHeater(const bool& option) {
	heater_ = option;
}