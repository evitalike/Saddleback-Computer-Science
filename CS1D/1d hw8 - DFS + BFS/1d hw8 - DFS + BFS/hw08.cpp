// ===================================================
// Program: DFS and BFS
// ===================================================
// Programmer: Aaron Geesink and Garrett Geesink
// Class: CS 1D - 5:00 PM M W
// ===================================================
// In this program, we will construct a graph of 12 cities. Part A performs a
// DFS on a graph using an adjacency list starting from Chicago,
// and part B performs a BFS on a graph using an adjacency matrix.
// the total amount travelled along discovery edges, back edges, or cross edges
// is added up and displayed as well.
// ===================================================

#include "ListGraph.h"
#include "MatrixGraph.h"
using namespace std;

const int SIZE = 12;

int main()
{
	cout << "===================================================\n"
		<< "Program: DFS and BFS\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink and Garrett Geesink\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "In this program, we will construct a graph of 12 cities. Part A performs a\n"
		<< "DFS on a graph using an adjacency list starting from Chicago,\n"
		<< "and part B performs a BFS on a graph using an adjacency matrix.\n"
		<< "the total amount travelled along discovery edges, back edges, or cross edges\n"
		<< "is added up and displayed as well.\n"
		<< "===================================================\n\n";

	string cities[SIZE] = { "Seattle", "Chicago", "Boston", "San Francisco", "Denver", "Los Angeles",
			"Kansas City", "New York", "Dallas", "Atlanta", "Houston", "Miami" };
	ListGraph<string> g(cities, SIZE);
	cout << "=================== Part A =====================\n";
	cout << "DFS Starting From Chicago\n\n";

	g.addEdge("Chicago", "Seattle", 2097);
	g.addEdge("Seattle", "San Francisco", 807);
	g.addEdge("San Francisco", "Los Angeles", 381);
	g.addEdge("Los Angeles", "Denver", 1015);
	g.addEdge("Denver", "Kansas City", 599);
	g.addEdge("New York", "Kansas City", 1260);
	g.addEdge("New York", "Boston", 214);
	g.addEdge("Miami", "Atlanta", 661);
	g.addEdge("Houston", "Miami", 1187);
	g.addEdge("Dallas", "Houston", 239);
	g.addEdge("Seattle", "Denver", 1331);
	g.addEdge("San Francisco", "Denver", 1267);
	g.addEdge("Los Angeles", "Kansas City", 1663);
	g.addEdge("Los Angeles", "Dallas", 1435);
	g.addEdge("New York", "Chicago", 787);
	g.addEdge("Dallas", "Kansas City", 496);
	g.addEdge("Dallas", "Atlanta", 781);
	g.addEdge("Houston", "Atlanta", 810);
	g.addEdge("Atlanta", "Kansas City", 864);
	g.addEdge("Atlanta", "New York", 888);
	g.addEdge("Boston", "Chicago", 983);
	g.addEdge("Chicago", "Denver", 1003);
	g.addEdge("Chicago", "Kansas City", 533);
	g.DFS("Chicago");

	cout << "\n\n=================== Part B ===================\n";
	string cities2[12] = { "Chicago", "Seattle", "San Francisco", "Los Angeles", "Denver", 
		"Kansas City", "Dallas", "Houston", "Miami", "Atlanta", "New York", "Boston" };
	MatrixGraph<string> mg(cities2, 12);

	mg.addEdge("Seattle", "San Francisco", 807);
	mg.addEdge("Seattle", "Denver", 1331);
	mg.addEdge("Seattle", "Chicago", 2097);
	mg.addEdge("San Francisco", "Los Angeles", 381);
	mg.addEdge("San Francisco", "Denver", 1267);
	mg.addEdge("Los Angeles", "Denver", 1015);
	mg.addEdge("Los Angeles", "Kansas City", 1663);
	mg.addEdge("Los Angeles", "Dallas", 1435);
	mg.addEdge("Dallas", "Kansas City", 496);
	mg.addEdge("Dallas", "Atlanta", 781);
	mg.addEdge("Dallas", "Houston", 239);
	mg.addEdge("Houston", "Atlanta", 810);
	mg.addEdge("Houston", "Miami", 1187);
	mg.addEdge("Miami", "Atlanta", 661);
	mg.addEdge("Atlanta", "Kansas City", 864);
	mg.addEdge("Atlanta", "New York", 888);
	mg.addEdge("New York", "Kansas City", 1260);
	mg.addEdge("New York", "Chicago", 787);
	mg.addEdge("New York", "Boston", 214);
	mg.addEdge("Boston", "Chicago", 983);
	mg.addEdge("Chicago", "Denver", 1003);
	mg.addEdge("Chicago", "Kansas City", 533);
	mg.addEdge("Denver", "Kansas City", 599);

	cout << "Here is the order of the Breadth First Traversal, starting from Chicago.\n";
	mg.BFS("Chicago");

	cout << endl;
	system("pause");
	return 0;
}

// ===================================================