// ===================================================
// Program: Assignment 2 - Stacks
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// This program demonstrates use of the STL stack class for Parts A and B
// as well as a custom singly linked list stack class for parts C and D.
// Part E demonstrates more usage of the custom Linked List class through an
// algorithm that checks for balanced parentheses in a math expression.
// ===================================================

#include <iostream>
#include <string>
#include <stack>
#include "LinkedListStack.h"
using namespace std;

void stackPrint(stack <double> s);
// function to print STL double stacks
// precondition: stack of type double as argument
// postcondition: stack elements printed and deleted

void stackPrint(stack <string> s);
// function to print STL string stacks
// precondition: stack of type string as argument
// postcondition: stack elements printed and deleted

bool parenthesesCheck(string expr);
// algorithm to print whether a string with parentheses is balanced
// precondition: string as argument
// postcondition: true if parentheses are balanced, else false

void printBalanced(string eq);
// driver function for parenthsis check function
// precondition: string as argument
// postcondition: console output telling if parentheses are balanced

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 2 - Stacks\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n";


	cout << "This program demonstrates use of the STL stack class for Parts A and B\n"
		<< "as well as a custom singly linked list stack class for parts C and D.\n"
		<< "Part E demonstrates more usage of the custom Linked List class through an\n"
		<< "algorithm that checks for balanced parentheses in a math expression.\n"
		<< "===================================================\n\n";

	// data initialization for the stacks used in the program
	string names[7] = { "Mark", "Alan", "Jennifer", "Sonny", "Eric", "JoAnn", "Bill" };
	double doubles[6] = { 983.3, 44.44, 888.55, 99.99, 123.123, 8.445 };

	stack<string> nameStack1;
	stack<string> nameStack2;
	stack<double> doubleStack1;
	stack<double> doubleStack2;

	LinkedListStack<string> nameStack3;
	LinkedListStack<string> nameStack4;
	LinkedListStack<double> doubleStack3;
	LinkedListStack<double> doubleStack4;


	for (int i = 0; i < 7; i++) 
	{
		nameStack1.push(names[i]);
		nameStack2.push(names[i]);
		nameStack3.push(names[i]);
		nameStack4.push(names[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		doubleStack1.push(doubles[i]);
		doubleStack2.push(doubles[i]);
		doubleStack3.push(doubles[i]);
		doubleStack4.push(doubles[i]);
	}

	cout << "Part A: Data from the STL name and float stacks:\n";
	stackPrint(nameStack1);
	stackPrint(doubleStack1);

	//popping 99.99 and Sonny from the double and name stack
	nameStack2.pop();
	nameStack2.pop();
	nameStack2.pop();
	nameStack2.pop();

	doubleStack2.pop();
	doubleStack2.pop();
	doubleStack2.pop();

	cout << "\nPart B: Data from the STL name and float stacks After 99.99 and Sonny are deleted:\n";
	stackPrint(nameStack2);
	stackPrint(doubleStack2);

	cout << "\nPart C: Data from the custom name and float stacks:\n";
	nameStack3.print();
	doubleStack3.print();

	//popping 99.99 and Sonny from the double and name stack
	nameStack4.pop();
	nameStack4.pop();
	nameStack4.pop();
	nameStack4.pop();

	doubleStack4.pop();
	doubleStack4.pop();
	doubleStack4.pop();

	cout << "\nPart D: Data from the custom name and float stacks After 99.99 and Sonny are deleted:\n";
	nameStack4.print();
	doubleStack4.print();

	// checking parentheses algorithm
	cout << "\nPart E: Parentheses Algorithm using custom stack:\n";
	printBalanced("{2x-8)(12x+6)");
	printBalanced("{{8x+5) - 5x[9x+3]})");
	printBalanced("{2x+5}(6x+4)");
	printBalanced("(((4x+8) - x[4x+3])))");
	printBalanced("[(5x - 5) - 4x[6x + 2]]");
	printBalanced("{(8x+5) - 6x[9x+3]]");
	printBalanced("(12x + 6)(2x - 4)");

	cout << endl;
	system("pause");
	return 0;
}

// ===================================================

// 
void stackPrint(stack <double> s)
{
	while (!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	cout << "\n";
}

void stackPrint(stack <string> s)
{
	while (!s.empty())
	{
		cout << s.top() << "  ";
		s.pop();
	}
	cout << "\n";
}

bool parenthesesCheck(string expr)
{
	LinkedListStack<char> s;
	char x;

	// Traversing the Expression 
	for (int i = 0; i < expr.length(); i++)
	{
		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
		{
			// Push the element in the stack 
			s.push(expr[i]);
			continue;
		}

		// IF current character is not opening 
		// bracket, then it must be closing. So stack 
		// cannot be empty at this point. 
		if (s.isEmpty())
			return false;

		switch (expr[i])
		{
		case ')':

			// Store the top element in a 
			x = s.topElem();
			s.pop();
			if (x == '{' || x == '[')
				return false;
			break;

		case '}':

			// Store the top element in b 
			x = s.topElem();
			s.pop();
			if (x == '(' || x == '[')
				return false;
			break;

		case ']':

			// Store the top element in c 
			x = s.topElem();
			s.pop();
			if (x == '(' || x == '{')
				return false;
			break;
		}
	}
	// Check Empty Stack 
	return (s.isEmpty());
}

void printBalanced(string eq)
{
	if (parenthesesCheck(eq))
		cout << eq << " : Balanced\n";
	else
		cout << eq << " : Not Balanced\n";
}
