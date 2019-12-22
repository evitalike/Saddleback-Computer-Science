// ===================================================
// Program: Assignment 6
// ===================================================
// Programmer: Garrett Geesink
// Class: CS 1D ÅE 5 PM class
// ===================================================

#include <iostream>
#include "map.h"
using namespace std;

int main()
{
	cout << "================== Part 1 ===================\n";
	cout << "Map using a double hashing algorithm\n";
	Map dHash;

	// inserting keys into hash table 
	dHash.insertDHash(18, "Laguna Nigel");
	dHash.insertDHash(41, "Mission Viejo");
	dHash.insertDHash(22, "San Clemente");
	dHash.insertDHash(44, "Irvine");
	dHash.deleteKey(41);
	dHash.insertDHash(58, "Lake Forest");
	dHash.insertDHash(32, "San Diego");
	dHash.insertDHash(49, "Anaheim");
	dHash.deleteKey(58);
	dHash.insertDHash(31, "Los Angeles");
	dHash.insertDHash(17, "Orange");
	dHash.insertDHash(72, "Palms Springs");
	dHash.insertDHash(41, "Riverside");
	dHash.deleteKey(72);
	dHash.insertDHash(19, "Brea");
	dHash.insertDHash(60, "Santa Ana");
	dHash.insertDHash(35, "Tustin");
	dHash.insertDHash(103, "Oceanside");
	dHash.insertDHash(11, "La Jolla");
	dHash.insertDHash(18, "Del Mar");
	dHash.insertDHash(22, "Aliso Viejo");
	dHash.insertDHash(49, "Laguna Beach");
	dHash.deleteKey(41);

	// display the hash Table 
	dHash.displayHash();

	cout << "\n================== Part 2 ===================\n";
	cout << "Map using a quadratic hashing algorithm\n";
	HashMap qHash;

	// inserting keys into hash table 
	qHash.insertQHash(18, "Laguna Nigel");
	qHash.insertQHash(41, "Mission Viejo");
	qHash.insertQHash(22, "San Clemente");
	qHash.insertQHash(44, "Irvine");
	qHash.deleteKey(41);
	qHash.insertQHash(58, "Lake Forest");
	qHash.insertQHash(32, "San Diego");
	qHash.insertQHash(49, "Anaheim");
	qHash.deleteKey(58);
	qHash.insertQHash(31, "Los Angeles");
	qHash.insertQHash(17, "Orange");
	qHash.insertQHash(72, "Palms Springs");
	qHash.insertQHash(41, "Riverside");
	qHash.deleteKey(72);
	qHash.insertQHash(19, "Brea");
	qHash.insertQHash(60, "Santa Ana");
	qHash.insertQHash(35, "Tustin");
	qHash.insertQHash(103, "Oceanside");
	qHash.insertQHash(11, "La Jolla");
	qHash.insertQHash(18, "Del Mar");
	qHash.insertQHash(22, "Aliso Viejo");
	qHash.insertQHash(49, "Laguna Beach");
	qHash.deleteKey(41);

	// display the hash Table 
	qHash.displayHash();

	system("pause");
	return 0;
}

// ===================================================
/* OUTPUT:

*/
// ===================================================