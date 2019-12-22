#include "Auto.h"

Auto::Auto(int id, string model, int numDoors) : Vehicle (id, model)
{
	//this->id = id;		<--These are now redundant, as the Vehicle constructor already initializes id and model
	//this->model = model;	<--
	this->numDoors = numDoors;
}

Auto::~Auto()
{
}

void Auto::showVehicle()
{
	cout << "ID:\t" << id << endl
		<< "Model:\t" << model << endl
		<< "Number of Doors:\t" << numDoors;
}
