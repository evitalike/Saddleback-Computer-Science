// ===================================================
// Program: Assignment 6 - Hashing Algorithms
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// This assignment demonstrates the use of hashing algorithms
// that assign elements to a map depending on an integer key.
// Part 1 utilizes a double hashing algorithm to assign elements,
// while part 2 uses a quadratic hashing algorithm.
// ===================================================

#include <iostream>
#include <string>
#include "map.h"
using namespace std;

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 6 - Hashing Algorithms\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "This assignment demonstrates the use of hashing algorithms\n"
		<< "that assign elements to a map depending on an integer key.\n"
		<< "Part 1 utilizes a double hashing algorithm to assign elements,\n"
		<< "while part 2 uses a quadratic hashing algorithm.\n"
		<< "===================================================\n\n";

	cout << "============ Part 1: Double Hash Map ============\n";
	Map doubleHashMap;

	// inserting keys into hash table 
	doubleHashMap.insertDoubleHash(18, "Laguna Nigel");
	doubleHashMap.insertDoubleHash(41, "Mission Viejo");
	doubleHashMap.insertDoubleHash(22, "San Clemente");
	doubleHashMap.insertDoubleHash(44, "Irvine");
	doubleHashMap.deleteKey(41);
	doubleHashMap.insertDoubleHash(58, "Lake Forest");
	doubleHashMap.insertDoubleHash(32, "San Diego");
	doubleHashMap.insertDoubleHash(49, "Anaheim");
	doubleHashMap.deleteKey(58);
	doubleHashMap.insertDoubleHash(31, "Los Angeles");
	doubleHashMap.insertDoubleHash(17, "Orange");
	doubleHashMap.insertDoubleHash(72, "Palms Springs");
	doubleHashMap.insertDoubleHash(41, "Riverside");
	doubleHashMap.deleteKey(72);
	doubleHashMap.insertDoubleHash(19, "Brea");
	doubleHashMap.insertDoubleHash(60, "Santa Ana");
	doubleHashMap.insertDoubleHash(35, "Tustin");
	doubleHashMap.insertDoubleHash(103, "Oceanside");
	doubleHashMap.insertDoubleHash(11, "La Jolla");
	doubleHashMap.insertDoubleHash(18, "Del Mar");
	doubleHashMap.insertDoubleHash(22, "Aliso Viejo");
	doubleHashMap.insertDoubleHash(49, "Laguna Beach");
	doubleHashMap.deleteKey(41);
	doubleHashMap.insertDoubleHash(42, "Vista");
	doubleHashMap.insertDoubleHash(49, "San Diego");
	doubleHashMap.insertDoubleHash(99, "San Juan");
	doubleHashMap.insertDoubleHash(29, "Dana Point");
	doubleHashMap.insertDoubleHash(88, "El Segundo");
	doubleHashMap.insertDoubleHash(41, "San Clemente");
	doubleHashMap.insertDoubleHash(62, "Laguna Hills");

	// display the hash Table 
	doubleHashMap.displayHash();

	cout << "\n=========== Part 2: Quadratic Hash Map ===========\n";
	Map quadHashMap;

	// inserting keys into hash table 
	quadHashMap.insertQuadHash(18, "Laguna Nigel");
	quadHashMap.insertQuadHash(41, "Mission Viejo");
	quadHashMap.insertQuadHash(22, "San Clemente");
	quadHashMap.insertQuadHash(44, "Irvine");
	quadHashMap.deleteKey(41);
	quadHashMap.insertQuadHash(58, "Lake Forest");
	quadHashMap.insertQuadHash(32, "San Diego");
	quadHashMap.insertQuadHash(49, "Anaheim");
	quadHashMap.deleteKey(58);
	quadHashMap.insertQuadHash(31, "Los Angeles");
	quadHashMap.insertQuadHash(17, "Orange");
	quadHashMap.insertQuadHash(72, "Palms Springs");
	quadHashMap.insertQuadHash(41, "Riverside");
	quadHashMap.deleteKey(72);
	quadHashMap.insertQuadHash(19, "Brea");
	quadHashMap.insertQuadHash(60, "Santa Ana");
	quadHashMap.insertQuadHash(35, "Tustin");
	quadHashMap.insertQuadHash(103, "Oceanside");
	quadHashMap.insertQuadHash(11, "La Jolla");
	quadHashMap.insertQuadHash(18, "Del Mar");
	quadHashMap.insertQuadHash(22, "Aliso Viejo");
	quadHashMap.insertQuadHash(49, "Laguna Beach");
	quadHashMap.deleteKey(41);
	quadHashMap.insertQuadHash(42, "Vista");
	quadHashMap.insertQuadHash(49, "San Diego");
	quadHashMap.insertQuadHash(99, "San Juan");
	quadHashMap.insertQuadHash(29, "Dana Point");
	quadHashMap.insertQuadHash(88, "El Segundo");
	quadHashMap.insertQuadHash(41, "San Clemente");
	quadHashMap.insertQuadHash(62, "Laguna Hills");

	// display the hash Table 
	quadHashMap.displayHash();

	system("pause");
	return 0;
}

// ===================================================