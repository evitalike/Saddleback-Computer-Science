#include "Vehicle.h"

Vehicle::Vehicle()
{
	id = 0;
}

Vehicle::Vehicle(int id, string model)
{
	this->id = id;
	this->model = model;
}

Vehicle::~Vehicle()
{
}

void Vehicle::showVehicle()
{
	cout << "ID:\t" << id
		<< "Model:\t" << model;
}
