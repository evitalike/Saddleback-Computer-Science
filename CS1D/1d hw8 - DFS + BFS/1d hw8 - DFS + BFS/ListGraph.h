#ifndef LISTGRAPH_H
#define LISTGRAPH_H

#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

template <typename T>
struct ListVertex
{
	T value;
	bool visited;
	int level;
	ListVertex<T>() : value(NULL), visited(false), level(0) {}
	ListVertex<T>(T va, bool vi) : value(va), visited(vi), level(0) {}
};

template <typename T>
struct ListEdge
{
	ListVertex<T>* vertex;
	int distance;
	ListEdge<T>() : vertex(new ListVertex<T>()), distance(0) {}
	ListEdge<T>(ListVertex<T> *v, int d) : vertex(v), distance(d) {}
};

template<typename T>
class ListGraph
{
private:
	T V;
	vector<ListVertex<T>> cities;
	int citiesAmount;
	int deTotal;
	int beTotal;
	list<ListEdge<T>> *adj;
	void DFSUtil(T v);
	bool checkConnection(T a, T b);

public:
	ListGraph(T* arr, int n);
	void addEdge(T a, T b, int length);
	void DFS(T v);
};

#endif

template<typename T>
inline void ListGraph<T>::DFSUtil(T v)
{
	int id = 0;
	for (int i = 0; i < citiesAmount; i++)
	{
		if (cities[i].value == v)
		{
			cities[i].visited = true;
			id = i;
		}
	}
	cout << v;
	typename list<ListEdge<T> >::iterator i;
	vector<ListEdge<T> > edges;
	for (i = adj[id].begin(); i != adj[id].end(); ++i)
	{
		edges.push_back(*i);
	}
	for (int i = 0; i < edges.size(); i++)
	{
		cout << " -> " << edges[i].vertex->value;
	}
	cout << endl;
	for (int i = 0; i < edges.size(); i++)
	{
		if (!edges[i].vertex->visited)
		{
			DFSUtil(edges[i].vertex->value);
			deTotal += edges[i].distance;
		}
		else
			beTotal += edges[i].distance;
	}
}

template<typename T>
inline bool ListGraph<T>::checkConnection(T a, T b)
{
	int id = 0;
	for (int i = 0; i < citiesAmount; i++)
	{
		if (cities[i].value == a)
		{
			id = i;
		}
	}
	typename list<ListEdge<T> >::iterator i;
	vector<ListEdge<T> > edges;
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
inline ListGraph<T>::ListGraph(T * arr, int n)
{
	citiesAmount = n;
	for (int i = 0; i < citiesAmount; i++)
	{
		ListVertex<T> s(arr[i], false);
		cities.push_back(s);
	}
	adj = new list<ListEdge<T> >[citiesAmount];
	deTotal = 0;
	beTotal = 0;
}

template<typename T>
inline void ListGraph<T>::addEdge(T a, T b, int length)
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
			ListEdge<T> e(&cities[id], length);
			adj[i].push_back(e);
		}
		if (cities[i].value == b)
		{
			int id = 0;
			for (int j = 0; j < citiesAmount; j++)
			{
				if (cities[j].value == a)
					id = j;
			}
			ListEdge<T> e(&cities[id], length);
			adj[i].push_back(e);
		}
	}
}

template<typename T>
inline void ListGraph<T>::DFS(T v)
{
	deTotal = 0;
	beTotal = 0;
	for (int i = 0; i < citiesAmount; i++)
		cities[i].visited = false;
	cout << "Here is the adjacency list and the order the cities are visited:\n";
	DFSUtil(v);
	cout << "\nDiscovery edge distance: " << deTotal;
	cout << "\nBack edge distance: " << beTotal;
}