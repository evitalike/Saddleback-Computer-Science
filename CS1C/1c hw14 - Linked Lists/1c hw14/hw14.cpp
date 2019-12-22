// ===================================================
// Program: hw14 - Linked Lists
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1C - 3:00 PM M T W Th
// ===================================================

#include "doublyLinkedList.h"
using namespace std;

int main()
{
	cout << "==========Testing Int Linked List==========\n";

	doublyLinkedList<int> intList;
	intList.insert(60);
	intList.insert(143);
	intList.insert(62);
	intList.insert(78);
	intList.insert(88);

	cout << "Part 1:\n"
		<< "Linked list 1:  ";
	intList.print();

	cout << "\nPart 2:\n";
	doublyLinkedList<int> copy1 = intList;
	doublyLinkedList<int> copy2;
	copy2 = intList;
	cout << "Linked List 1 Copy constructor:  ";
	copy1.print();
	cout << "Linked List 1 Copy assignment:  ";
	copy2.print();

	cout << "\nPart 3:\n";
	doublyLinkedList<int> reverseList;
	reverseList.reverse(intList);
	cout << "Linked List 2:  ";
	reverseList.print();

	cout << "\nPart 4 (after deleting third node):\n";
	intList.remove(3);
	reverseList.remove(3);
	cout << "Linked list 1:  ";
	intList.print();
	cout << "Linked list 2:  ";
	reverseList.print();

	cout << "Trying to delete a non-existent node\n";
	intList.remove(5);

	cout << "Trying to delete from an empty list\n";
	doublyLinkedList<int> dList;
	dList.remove();

	cout << "\nPart 5 (after adding a node in the middle of the list):\n";
	intList.insert(70, 3);
	reverseList.insert(70, 3);
	cout << "Linked list 1:  ";
	intList.print();
	cout << "Linked list 2:  ";
	reverseList.print();


	cout << "\n==========Testing Double Linked List==========\n";

	doublyLinkedList<double> doubleList;
	doubleList.insert(1.1);
	doubleList.insert(2.2);
	doubleList.insert(3.3);
	doubleList.insert(4.4);
	doubleList.insert(5.5);

	cout << "Part 1:\n"
		<< "Linked list 1:  ";
	doubleList.print();

	cout << "\nPart 2:\n";
	doublyLinkedList<double> copy3 = doubleList;
	doublyLinkedList<double> copy4;
	copy4 = doubleList;
	cout << "Linked List 1 Copy constructor:  ";
	copy4.print();
	cout << "Linked List 1 Copy assignment:  ";
	copy4.print();

	cout << "\nPart 3:\n";
	doublyLinkedList<double> dreverseList;
	dreverseList.reverse(doubleList);
	cout << "Linked List 2:  ";
	dreverseList.print();

	cout << "\nPart 4 (after deleting third node):\n";
	doubleList.remove(3);
	dreverseList.remove(3);
	cout << "Linked list 1:  ";
	doubleList.print();
	cout << "Linked list 2:  ";
	dreverseList.print();

	cout << "Trying to delete a non-existent node\n";
	doubleList.remove(5);

	cout << "Trying to delete from an empty list\n";
	doublyLinkedList<double> emptyList;
	emptyList.remove();

	cout << "\nPart 5 (after adding a node in the middle of the list):\n";
	doubleList.insert(3.3, 3);
	dreverseList.insert(3.3, 3);
	cout << "Linked list 1:  ";
	doubleList.print();
	cout << "Linked list 2:  ";
	dreverseList.print();

	system("pause");
	return 0;
}
