/*
Environment.h
Andrew Ng
Dec 8 2019
header for Environment class
*/


#pragma once

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H


// Environment class
class Environment
{
public:
	// constructor defaults to heater off, room temp
	Environment() : heater_{ 0 }, temperature_{ 68 }
	{}

	void iteration();

	int getTemp() const;

	void setHeater(const bool& option);

private:
	bool heater_;
	int temperature_;
};

#endif