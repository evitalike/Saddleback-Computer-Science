// ===================================================
// Program: Assignment 9 - Directed DFS and BFS
// ===================================================
// Programmer: Aaron Geesink and Faris Hijazi
// Class: CS 1D - 5:00 PM M W
// ===================================================
// In this program, we will construct directed graphs of 12 cities. Part A performs a
// DFS on a directed graph using an adjacency list starting from Chicago,
// and part B performs a BFS on a directed graph using an adjacency matrix.
// Discovery, back, forward, and cross edges are labeled for each traversal,
// and the sum of the discovery edges is added up and displayed.
// Part C checks to see if the graph is strongly connected.
// ===================================================

#include "graphAdjList.h"
#include "MatrixGraph.h"

int main()
{
	cout << "===================================================\n"
		<< "Program: Assignment 9 - Directed DFS and BFS\n"
		<< "===================================================\n"
		<< "Programmer: Aaron Geesink and Faris Hijazi\n"
		<< "Class: CS 1D - 5:00 PM M W\n"
		<< "===================================================\n"
		<< "In this program, we will construct directed graphs of 12 cities. Part A performs a\n"
		<< "DFS on a directed graph using an adjacency list starting from Chicago,\n"
		<< "and part B performs a BFS on a directed graph using an adjacency matrix.\n"
		<< "Discovery, back, forward, and cross edges are labeled for each traversal,\n"
		<< "and the sum of the discovery edges is added up and displayed.\n"
		<< "Part C checks to see if the graph is strongly connected.\n"
		<< "===================================================\n\n";

	cout << "=================== Part A =====================\n";
	cout << "DFS Starting From Chicago\n\n";
    graphAdjList graph1;

    std::cout<< "ADJACENCY LIST:" << std::endl << std::endl;

    graph1.addEdge(Seattle, Denver, 1331);
    graph1.addEdge(Seattle, SanFrancisco, 807);
    graph1.addEdge(Chicago, Seattle, 2097);
    graph1.addEdge(Chicago, Boston, 983);
    graph1.addEdge(Denver, Chicago, 1003);
    graph1.addEdge(KansasCity, Chicago, 533);
    graph1.addEdge(NewYork, Chicago, 787);
    graph1.addEdge(Denver, SanFrancisco, 1267);
    graph1.addEdge(SanFrancisco, LosAngeles, 381);
    graph1.addEdge(LosAngeles, Denver, 1015);
    graph1.addEdge(KansasCity, Denver, 599);
    graph1.addEdge(KansasCity, LosAngeles, 1663);
    graph1.addEdge(Dallas, LosAngeles, 1435);
    graph1.addEdge(Dallas, KansasCity, 496);
    graph1.addEdge(KansasCity, NewYork, 1260);
    graph1.addEdge(KansasCity, Atlanta, 864);
    graph1.addEdge(Dallas, Atlanta, 781);
    graph1.addEdge(Houston, Dallas, 239);
    graph1.addEdge(Houston, Atlanta, 810);
    graph1.addEdge(Miami, Houston, 1187);
    graph1.addEdge(Atlanta, Miami, 661);
    graph1.addEdge(NewYork, Atlanta, 888);
    graph1.addEdge(Boston, NewYork, 214);
    graph1.sortByDist();
    graph1.printGraph();
    std::cout << std::endl << std::endl << "DFS TRAVERSAL: \n";
    graph1.DFS1();

	cout << "\n\n=================== Part B ===================\n";
	string cities2[12] = { "Chicago", "Boston", "Seattle", "Dallas", "Kansas City", "San Francisco", "Los Angeles", "Denver",
		"Houston", "Miami", "Atlanta", "New York" };
	MatrixGraph<string> graph2(cities2, 12);

	graph2.addEdge("Chicago", "Boston", 983);
	graph2.addEdge("Chicago", "Seattle", 2097);
	graph2.addEdge("Boston", "New York", 214);
	graph2.addEdge("Seattle", "San Francisco", 807);
	graph2.addEdge("Seattle", "Denver", 1331);
	graph2.addEdge("San Francisco", "Los Angeles", 381);
	graph2.addEdge("Los Angeles", "Denver", 1015);
	graph2.addEdge("Dallas", "Kansas City", 496);
	graph2.addEdge("Dallas", "Atlanta", 781);
	graph2.addEdge("Dallas", "Los Angeles", 1435);
	graph2.addEdge("Houston", "Dallas", 239);
	graph2.addEdge("Houston", "Atlanta", 810);
	graph2.addEdge("Miami", "Houston", 1187);
	graph2.addEdge("Atlanta", "Miami", 661);
	graph2.addEdge("New York", "Chicago", 787);
	graph2.addEdge("New York", "Atlanta", 888);
	graph2.addEdge("Denver", "Chicago", 1003);
	graph2.addEdge("Denver", "San Francisco", 1267);
	graph2.addEdge("Kansas City", "Chicago", 533);
	graph2.addEdge("Kansas City", "Denver", 599);
	graph2.addEdge("Kansas City", "New York", 1260);
	graph2.addEdge("Kansas City", "Los Angeles", 1663);
	graph2.addEdge("Kansas City", "Atlanta", 864);

	cout << "Here is the order of the Breadth First Traversal, starting from Chicago.\n";
	graph2.BFS("Chicago");

	cout << "\n\n=================== Part C ===================\n";
	cout << "Checking if the graph is strongly connected:\n\n";
	graph1.checkConnection();

	cout << endl;
	system("pause");
	return 0;
}