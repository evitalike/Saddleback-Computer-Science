#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct Vert
{
	T value;
	bool visited;
	int startTime = -1;
	int endTime = -1;
	Vert<T>() : value(NULL), visited(false), startTime(-1), endTime(-1) {}
	Vert<T>(T va, bool vi) : value(va), visited(vi), startTime(-1), endTime(-1) {}
};

template <typename T>
struct Edg
{
	Vert<T>* vertex;
	int distance;
	Edg<T>() : vertex(new Vert<T>()), distance(0) {}
	Edg<T>(Vert<T> *v, int d) : vertex(v), distance(d) {}
};

template<typename T>
class Graph
{
private:
	T V;
	vector<Vert<T>> cities;
	vector<Edg<T>> de;
	vector<Edg<T>> be;
	vector<Edg<T>> fe;
	vector<Edg<T>> ce;
	int citiesAmount;
	int deTotal;
	int beTotal;
	int feTotal;
	int ceTotal;
	int counter = 0;
	list<Edg<T>> *adj;
	void DFSUtil(T v);
	bool checkConnection(T a, T b);

public:
	Graph(T* arr, int n);
	void addEdge(T a, T b, int length);
	void DFS(T v);
};

#endif

template<typename T>
inline void Graph<T>::DFS(T v)
{
	for (int i = 0; i < citiesAmount; i++)
		cities[i].visited = false;
	cout << "Here is the adjacency list:\n";
	DFSUtil(v);

	cout << "\nDiscovery Edges:\n" << de[0].distance;
	for (int i = 1; i < de.size(); i++)
		cout << ", " << de[i].distance;
	cout << "\nDiscovery edge distance: " << deTotal << "\n";

	cout << "\nBack Edges:\n" << be[0].distance;
	for (int i = 1; i < be.size(); i++)
		cout << ", " << be[i].distance;
	cout << "\nBack edge distance: " << beTotal << "\n";

	cout << "\nForward Edges:\n" << fe[0].distance;
	for (int i = 1; i < fe.size(); i++)
		cout << ", " << fe[i].distance;
	cout << "\nForward edge distance: " << feTotal << "\n";

	cout << "\nCross Edges:\n" << ce[0].distance;
	for (int i = 1; i < ce.size(); i++)
		cout << ", " << ce[i].distance;
	cout << "\nCross edge distance: " << ceTotal << "\n";
	counter = 0;
}

template<typename T>
inline void Graph<T>::DFSUtil(T v)
{
	int id = 0;

	// Set the current city to visited and track its startTime
	for (int i = 0; i < citiesAmount; i++)
	{
		if (cities[i].value == v)
		{
			cities[i].visited = true;
			cities[i].startTime = counter;
			id = i;
		}
	}
	cout << v;
	typename list<Edg<T> >::iterator i;
	vector<Edg<T>> edges;
	for (i = adj[id].begin(); i != adj[id].end(); ++i)
	{
		edges.push_back(*i);
	}
	for (int i = 0; i < edges.size(); i++)
	{
		cout << " -> " << edges[i].vertex->value;
	}
	cout << endl;
	int time = counter; // Track the current time
	for (int i = 0; i < edges.size(); i++)
	{
		// Get all discovery edges
		if (!edges[i].vertex->visited)
		{
			counter++;
			DFSUtil(edges[i].vertex->value);
			counter++;
			edges[i].vertex->endTime = counter;
			deTotal += edges[i].distance;
			de.push_back(edges[i]);
		}
		// Get all back edges
		else if (edges[i].vertex->endTime == -1)
		{
			//cout << edges[i].distance << endl;
			beTotal += edges[i].distance;
			be.push_back(edges[i]);
		}
		// Get all forward edges
		else if (edges[i].vertex->endTime != -1 && edges[i].vertex->endTime > time)
		{
			//cout << edges[i].distance << endl;
			feTotal += edges[i].distance;
			fe.push_back(edges[i]);
		}
		// Get cross edges
		else
		{
			//cout << edges[i].distance << endl;
			ceTotal += edges[i].distance;
			ce.push_back(edges[i]);
		}
	}
}

template<typename T>
inline bool Graph<T>::checkConnection(T a, T b)
{
	int id = 0;
	for (int i = 0; i < citiesAmount; i++)
	{
		if (cities[i].value == a)
		{
			id = i;
		}
	}
	typename list<Edg<T> >::iterator i;
	vector<Edg<T> > edges;
	for (i = adj[id].begin(); i != adj[id].end(); ++i)
	{
		edges.push_back(*i);
	}
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].vertex->value == b)
			return true;
	}
	return false;
}

template<typename T>
inline Graph<T>::Graph(T * arr, int n)
{
	citiesAmount = n;
	for (int i = 0; i < citiesAmount; i++)
	{
		Vert<T> s(arr[i], false);
		cities.push_back(s);
	}
	adj = new list<Edg<T> >[citiesAmount];
	deTotal = 0;
	beTotal = 0;
	feTotal = 0;
	ceTotal = 0;
}

template<typename T>
inline void Graph<T>::addEdge(T a, T b, int length)
{
	for (int i = 0; i < citiesAmount; i++)
	{
		if (cities[i].value == a)
		{
			int id = 0;
			for (int j = 0; j < citiesAmount; j++)
			{
				if (cities[j].value == b)
					id = j;
			}
			Edg<T> e(&cities[id], length);
			adj[i].push_back(e);
		}
	}
}