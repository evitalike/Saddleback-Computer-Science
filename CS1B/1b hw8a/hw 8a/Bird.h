#pragma once
#include "Animal.h"

class Bird : public Animal
{
private:
	string featherColor;

public:
	Bird(string name, double weight, string featherColor) : Animal(name, weight)
	{
		this->featherColor = featherColor;
	}
	// -------------------------------
	~Bird() {}
	// -------------------------------
	void showAnimal()
	{
		cout << "Birds are vertebrates in the Aves class.\n"
			<< "This " << name << " has " << featherColor << " feathers and weighs " << weight << " pounds.\n\n";

	}
};