#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
	int r; //radius

public:
	Circle(int r, int x, int y) : r{ r }, Shape(x, y)
	{ }

	void print()
	{
		cout << "Circle Data:\n";
		cout << "Coordinates:  (" << this->getX() << ", " << this->getY() << ")\n"
			<< "Radius:  " << r << "\n\n";
	}

	void updateDimensions(Dim dim)
	{
		this->r = dim.r;
	}
};

#endif