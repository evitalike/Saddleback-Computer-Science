#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
public:
	virtual float calcPerimeter() = 0;
	// pure virtual function to return a shape's perimeter
	// implementation in inherited classes

	virtual float calcArea() = 0;
	// pure virtual function to return a shape's area
	// implementation in inherited classes

};

#endif