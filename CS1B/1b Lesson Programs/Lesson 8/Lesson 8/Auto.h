#ifndef AUTO_H
#define AUTO_H

#include "Vehicle.h"

class Auto : public Vehicle
{
private:
	int numDoors;

public:
	Auto(int id, string model, int numDoors);
	~Auto();
	void showVehicle();
};

#endif