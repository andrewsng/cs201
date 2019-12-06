#pragma once


class Simulator
{
public:
	void run();

	void askOwner();

	int getTarget() const;

private:
	int targetTemp_;
};

