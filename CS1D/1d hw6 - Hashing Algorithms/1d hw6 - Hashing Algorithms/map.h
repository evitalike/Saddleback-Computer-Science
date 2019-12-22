#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
using namespace std;

// Hash table size 
#define TABLE_SIZE 29 
// Used in second hash function. 
#define PRIME 13

struct hashTable
{
	string name;
	int key;
};

class Map
{
private:
	// Pointer to an array containing buckets 
	hashTable *table;
	int curr_size;

public:
	// Map constructor
	Map();

	// function to check if hash table is full 
	bool isFull();

	// function to calculate first hash 
	int hash1(int key);

	// function to calculate second hash 
	int hash2(int key);

	// function to insert key into hash table using a double hashing algorithm
	void insertDoubleHash(int key, string data);

	// function to insert key into hash table using a quadratic hashing algorithm
	void insertQuadHash(int key, string data);

	// function to delete value at key in hash table
	void deleteKey(int key);

	// function to display the hash table 
	void displayHash();
};

#endif