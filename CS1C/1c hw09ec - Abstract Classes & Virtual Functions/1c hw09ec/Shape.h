#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

struct Dim
{
	int w;
	int l;
	int r;
};

class Shape
{
private:
	int x; // x-coordinate
	int y; // y-coordinate

public:
	Shape(int x, int y) : x{ x }, y{ y }
	{ }

	int getX()
	{
		return this->x;
	}

	int getY()
	{
		return this->y;
	}

	void print()
	{
		cout << "Coordinates:  (" << x << ", " << y << ")\n";
	}

	virtual void move(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	virtual void updateDimensions(Dim dim) = 0;
	
};

#endif