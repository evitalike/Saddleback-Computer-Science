#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
	int id;
	string model;
public:
	Vehicle();
	Vehicle(int id, string model);
	~Vehicle();
	void showVehicle();
};
#endif