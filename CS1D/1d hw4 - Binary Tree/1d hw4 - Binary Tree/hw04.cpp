// ===================================================
// Program: Assignment 4 - Binary Tree
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// The purpose of this program is to create a binary
// tree with 19 elements, and then display the 
// elements in the tree using the 4 methods of traversal.
// The tree is then displayed graphically.
// ===================================================

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 4 - Binary Tree\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "The purpose of this program is to create a binary\n"
		<< "tree with 19 elements, and then display the\n"
		<< "elements in the tree using the 4 methods of traversal.\n"
		<< "The tree is then displayed graphically.\n"
		<< "===================================================\n\n";

	BinaryTree<int> tree;
	const int SIZE = 19;
	int numbers[SIZE] = { 19, 13, 888, 109, 55, 118, 89, 33, 1001, 18, 44, 88, 12, 24, 49, 7, 25, 59, 28 };

	for (int i = 0; i < SIZE; i++)
	{
		tree.insert(numbers[i]);
	}

	cout << "Preorder traversal:\n";
	tree.preorderPrint();

	cout << "\nInorder traversal:\n";
	tree.inorderPrint();

	cout << "\nPostorder traversal:\n";
	tree.postorderPrint();

	cout << "\nBreadth First traversal:\n";
	tree.breadthFirstPrint();

	cout << "\nHere is the tree:\n";
	tree.print();

	system("pause");
	return 0;
}

// ===================================================