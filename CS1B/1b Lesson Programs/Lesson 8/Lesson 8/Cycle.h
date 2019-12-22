#ifndef CYCLE_H
#define CYCLE_H

#include "Vehicle.h";

class Cycle : public Vehicle
{
private:
	bool sideCar;
public:
	Cycle(int id, string model, bool sideCar);
	~Cycle();
	void showVehicle();
};

#endif