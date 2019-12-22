#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
	int l; // length
	int w; // width

public:
	Rectangle(int l, int w);
	// rectangle constructor which inherits from shape
	// postcondition: this->l = l; this->w = w;

	float calcPerimeter();
	// pure virtual function to return a shape's perimeter
	// postcondition: the perimiter of the shape is returned.

	float calcArea();
	// pure virtual function to return a shape's area
	// postcondition: the area of the shape is returned.

};

#endif