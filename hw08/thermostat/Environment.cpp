#include "Environment.h"


void Environment::iteration() {
	if (heater_) {
		temperature_++;
	}
	else {
		temperature_--;
	}
}


int Environment::getTemp() const {
	return temperature_;
}


void Environment::setHeater(const bool& option) {
	heater_ = option;
}