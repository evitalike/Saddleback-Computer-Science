// ===================================================
// Program: Assignment 10 - A-Star Pathfinding and MST
// ===================================================
// Programmer: Aaron Geesink and Ali Parva
// Class: CS 1D - 5:00 PM M W
// ===================================================
// This Program demonstrates the use of and A* pathfinding algorithm starting from Atlanta
// and a Minimum Spanning Tree Diagram of a Adjacency Matrix graph of cities.
// The edges on the graph are bidirectional, and the sum of the distance
// traversed is displayed for the edges traversed in each algorithm.
// ===================================================

#include "MatrixGraph.h"

const int SIZE = 12;

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 10 - A-Star Pathfinding and MST\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink and Ali Parva\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "This Program demonstrates the use of and A* pathfinding algorithm starting from Atlanta\n"
		<< "and a Minimum Spanning Tree Diagram of a Adjacency Matrix graph of cities.\n"
		<< "The edges on the graph are bidirectional, and the sum of the distance\n"
		<< "traversed is displayed for the edges traversed in each algorithm.\n"
		<< "===================================================\n\n";

	string cities[SIZE] = { "Chicago", "Boston", "Seattle", "Dallas", "Kansas City", "San Francisco", "Los Angeles", "Denver",
		"Houston", "Miami", "Atlanta", "New York" };
	MatrixGraph<string> cityGraph(cities, SIZE);

	cityGraph.addEdge("Chicago", "Boston", 983);
	cityGraph.addEdge("Chicago", "Seattle", 2097);
	cityGraph.addEdge("Boston", "New York", 214);
	cityGraph.addEdge("Seattle", "San Francisco", 807);
	cityGraph.addEdge("Seattle", "Denver", 1331);
	cityGraph.addEdge("San Francisco", "Los Angeles", 381);
	cityGraph.addEdge("Los Angeles", "Denver", 1015);
	cityGraph.addEdge("Dallas", "Kansas City", 496);
	cityGraph.addEdge("Dallas", "Atlanta", 781);
	cityGraph.addEdge("Dallas", "Los Angeles", 1435);
	cityGraph.addEdge("Houston", "Dallas", 239);
	cityGraph.addEdge("Houston", "Atlanta", 810);
	cityGraph.addEdge("Miami", "Houston", 1187);
	cityGraph.addEdge("Atlanta", "Miami", 661);
	cityGraph.addEdge("New York", "Chicago", 787);
	cityGraph.addEdge("New York", "Atlanta", 888);
	cityGraph.addEdge("Denver", "Chicago", 1003);
	cityGraph.addEdge("Denver", "San Francisco", 1267);
	cityGraph.addEdge("Kansas City", "Chicago", 533);
	cityGraph.addEdge("Kansas City", "Denver", 599);
	cityGraph.addEdge("Kansas City", "New York", 1260);
	cityGraph.addEdge("Kansas City", "Los Angeles", 1663);
	cityGraph.addEdge("Kansas City", "Atlanta", 864);

	cityGraph.displayGraph();



	cout << "\n=================== Part A ===================\n";
	cout << "Here are the A* traversals from Atlanta to every other city, including distance of each path:\n\n";

	string targetCity;
	for (int i = 0; i < SIZE; i++)
	{
		targetCity = cities[i];
		cityGraph.aStar("Atlanta", targetCity);
	}

	cout << "\n=================== Part C ===================\n";
	cout << "Here is the DFS Traversal:\n\n";
	cityGraph.DFS("Chicago");

	cout << "\n=================== Part D ===================\n";
	cout << "Here is the BFS Traversal:\n\n";
	cityGraph.BFS("Chicago");


	cout << "\n=================== Part B ===================\n";
	cout << "Here are the edges of the MST Traversal:\n\n";

	cout << "Total Distance: " << cityGraph.kruskalMST() << "\n\n";

	system("pause");
	return 0;
}