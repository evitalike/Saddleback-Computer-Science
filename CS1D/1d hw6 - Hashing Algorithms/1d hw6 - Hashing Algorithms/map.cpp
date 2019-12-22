#include "Map.h"

bool Map::isFull()
{
	// if hash size reaches maximum size 
	return (curr_size == TABLE_SIZE);
}

int Map::hash1(int key)
{
	return (key % TABLE_SIZE);
}

int Map::hash2(int key)
{
	return (PRIME - (key % PRIME));
}

Map::Map() : table{ new hashTable[TABLE_SIZE] }, curr_size{ 0 }
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		table[i].name = "";
		table[i].key = 0;
	}
}


void Map::insertDoubleHash(int key, string data)
{
	// if hash table is full 
	if (isFull())
		return;

	// get index from first hash 
	int index = hash1(key);

	// if collision occurs 
	if (table[index].name != "" && table[index].key != key)
	{
		// get index2 from second hash 
		int index2 = hash2(key);
		int i = 1;
		while (1)
		{
			// get newIndex 
			int newIndex = (index + i * index2) % TABLE_SIZE;

			// if no collision occurs, store 
			// the key 
			if (table[newIndex].name == "")
			{
				table[newIndex].name = data;
				table[newIndex].key = key;
				break;
			}
			i++;
		}
	}

	// if no collision occurs 
	else
	{
		table[index].name = data;
		table[index].key = key;
	}
	curr_size++;
}

void Map::insertQuadHash(int key, string data)
{
	// if hash table is full 
	if (isFull())
		return;

	// get index from first hash 
	int index = hash1(key);

	// if collision occurs 
	if (table[index].name != "" && table[index].key != key)
	{
		int i = 1;
		while (true)
		{
			// get newIndex 
			int newIndex = (key + i * i) % TABLE_SIZE;

			// if no collision occurs, store the key 
			if (table[newIndex].name == "")
			{
				table[newIndex].name = data;
				table[newIndex].key = key;
				break;
			}
			i++;
		}
	}

	// if no collision occurs 
	else
	{
		table[index].name = data;
		table[index].key = key;
	}
	curr_size++;
}

void Map::deleteKey(int key)
{
	table[hash1(key)].name = "";
}

void Map::displayHash()
{
	cout << "how to read: index ===> key, city\n\n";
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (table[i].name != "")
			cout << i << " ===> " << table[i].key << ", " << table[i].name << endl;
		else
			cout << i << endl;
	}
}
