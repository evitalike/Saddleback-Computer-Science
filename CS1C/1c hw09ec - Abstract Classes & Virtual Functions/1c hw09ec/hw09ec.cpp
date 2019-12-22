// ===================================================
// Program: hw09ec
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

void drawShape(Shape* pShape, int x, int y, Dim dim);

int main()
{
	Circle * pCircle = new Circle(5, 2, 2);
	Rectangle * pRectangle = new Rectangle(5, 5, 1, 1);
	Dim radius1{ 0,0,6 };
	Dim lengthWidth1{ 10, 10, 0 };

	cout << "Inititalized data:\n";
	pCircle->print();
	pRectangle->print();

	pCircle->move(10, 10);
	pRectangle->move(20, 20);
	pCircle->updateDimensions(radius1);
	pRectangle->updateDimensions(lengthWidth1);

	cout << "data after move and updateDimensions:\n";
	pCircle->print();
	pRectangle->print();

	Dim radius2{ 0,0,20 };
	Dim lengthWidth2{ 20, 20, 0 };
	drawShape(pCircle, 3, 3, radius2);
	drawShape(pRectangle, 4, 4, lengthWidth2);

	cout << "data after drawShape:\n";
	pCircle->print();
	pRectangle->print();

	system("pause");
	return 0;
}

// ===================================================

void drawShape(Shape * pShape, int x, int y, Dim dim)
{
	pShape->updateDimensions(dim);
	pShape->move(x, y);
}
