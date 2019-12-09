#pragma once


class Simulator
{
public:
	Simulator() : targetTemp_{ 68 }
	{}

	void run();

	bool askOwner();

	int getTarget() const;

private:
	int targetTemp_;
};