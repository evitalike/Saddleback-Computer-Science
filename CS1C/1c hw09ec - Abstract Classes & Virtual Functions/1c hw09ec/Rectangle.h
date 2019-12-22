#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
	int l; // length
	int w; // width

public:
	Rectangle(int l, int w, int x, int y) : l{ l }, w{ w }, Shape(x,y)
	{ }

	void updateDimensions(Dim dim)
	{
		this->l = dim.l;
		this->w = dim.w;
	}

	void print()
	{
		cout << "Rectangle data:\n";
		cout << "Coordinates:  (" << this->getX() << ", " << this->getY() << ")\n"
			<< "Length:  " << l << '\n'
			<< "Width:  " << w << "\n\n";
	}
};

#endif