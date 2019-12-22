#include "Cycle.h"

Cycle::Cycle(int id, string model, bool sideCar)
{
	this->id = id;
	this->model = model;
	this->sideCar = sideCar;
}

Cycle::~Cycle()
{
}

void Cycle::showVehicle()
{
	cout << "ID:\t" << id << endl
		<< "Model:\t" << model << endl
		<< "SideCar:\t";
	if (sideCar)
		cout << "yes";
	else
		cout << "no";
};
