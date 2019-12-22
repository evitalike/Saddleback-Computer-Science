// ===================================================
// Program: hw 09 - Abstract Classes & Virtual Functions
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W TH
// ===================================================

#include "Rectangle.h"
#include "Triangle.h"
#include "Shape.h"
#include <iostream>
using namespace std;

void printPerimeter(Shape * pShape);
// function that prints a shape object's perimeter to the console.
// postcondition: perimeter of a shape is outputted to the terminal

void printArea(Shape * pShape);
// function that prints a shape object's area to the console.
// postcondition: area of a shape is outputted to the terminal

int main()
{
	Rectangle *pRectangle = new Rectangle(5, 5);
	Triangle *pTriangle = new Triangle(3, 4, 5);

	cout << "Here is the data for the rectangle:\n";
	printArea(pRectangle);
	printPerimeter(pRectangle);

	cout << "\nHere is the data for the triangle:\n";
	printArea(pTriangle);
	printPerimeter(pTriangle);

	system("pause");
	return 0;
}

// ===================================================

void printPerimeter(Shape * pShape)
{
	cout << "This shape's perimeter is:  " << pShape->calcPerimeter() << "\n";
}

void printArea(Shape * pShape)
{
	cout << "This shape's area is:  " << pShape->calcArea() << "\n";
}
