#include "Triangle.h"

Triangle::Triangle(int s1, int s2, int s3) : s1{ s1 }, s2{ s2 }, s3{ s3 }, Shape()
{ }

float Triangle::calcPerimeter()
{
	return s1 + s2 + s3;
}

float Triangle::calcArea()
{
	int p = (s1 + s2 + s3) / 2;
	return sqrt(p * (p - s1) * (p - s2) * (p - s3)); // Heron's formula
}
