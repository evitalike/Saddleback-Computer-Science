#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>
using namespace std;

class Triangle : public Shape
{
private:
	int s1; // side 1
	int s2; // side 2
	int s3; // side 3

public:
	Triangle(int s1, int s2, int s3);
	// Triangle constructor which inherits from shape
	// postcondition: this->s1 = s1; this->s2 = s2; this->s3 = s3;

	float calcPerimeter();
	// pure virtual function to return a shape's perimeter
	// postcondition: the perimiter of the shape is returned.

	float calcArea();
	// pure virtual function to return a shape's area
	// postcondition: the area of the shape is returned.
};

#endif