#pragma once


class Environment
{
public:
	Environment() : heater_{ 0 }, temperature_{ 68 }
	{}

	void iteration();

	int getTemp() const;

	void setHeater(const bool& option);

private:
	bool heater_;
	int temperature_;
};