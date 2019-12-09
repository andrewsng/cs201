#pragma once


class Environment
{
public:
	void iteration();

	int getTemp() const;

	void setHeater(const bool& option);

private:
	bool heater_;
	int temperature_;
};

