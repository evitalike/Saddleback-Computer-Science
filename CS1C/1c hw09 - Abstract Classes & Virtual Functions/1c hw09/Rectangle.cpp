#include "Rectangle.h"

Rectangle::Rectangle(int l, int w) : l{ l }, w{ w }
{ }

float Rectangle::calcPerimeter()
{
	return 2 * l + 2 * w;
}

float Rectangle::calcArea()
{
	return l * w;
}
