#include "Car.h"

Car::Car(int year, string model)
{
	this->year = year;
	this->model = model;
}

Car::~Car()
{
}

void Car::getInfo(Car & car)
{
	cout << "Enter the Year:\t";
	cin >> year;
	cin.ignore();
	cout << "Enter the Model:\t";
	getline(cin, model);
}

void Car::showInfo(Car & car)
{
	cout << "Year:\t" << car.year << endl;
	cout << "Model:\t" << car.model << endl;
}
