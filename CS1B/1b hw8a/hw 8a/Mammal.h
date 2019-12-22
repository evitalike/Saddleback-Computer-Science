#pragma once
#include "Animal.h";

class Mammal : public Animal
{
private:
	string hairColor;

public:
	Mammal(string name, double weight, string hairColor) : Animal(name, weight)
	{
		this->hairColor = hairColor;
	}
	// -------------------------------
	~Mammal() {}
	// -------------------------------
	void showAnimal()
	{
		cout << "Mammals are vertebrates in the Mammalia class.\n"
			<< "This " << hairColor << " " << name << " weighs " << weight << " pounds.\n\n";

	}
};