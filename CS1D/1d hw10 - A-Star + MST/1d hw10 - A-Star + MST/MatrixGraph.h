// C++ implementation of the approach 
#include <vector> 
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

// forward declaration of vertex class
template <typename T>
struct Vertex;

template <typename T>
struct Edge
{
	T start;
	T end;
	int weight;
	Vertex<T>* pEndVertex;
};

template <typename T>
struct Vertex
{
	T vertex;	// data stored in the vertex
	vector<Edge<T>> edges;	// edges of the vertex
	int depth;	// depth for BFS
	Vertex<T>* parent;	// pointer to parent vertex in current traversal
	int cost;	// cost for A-Star Pathfinding
};

template <typename T>
class MatrixGraph 
{
private:
	int numVertices;	// Number of vertex 
	int numEdges;	// Number of edges 
	int** adj;	// Adjacency matrix
	Vertex<T>* vertices;	// Vertices of the graph
	vector<pair<int,pair<int, int>>> edges;	// edges of the graph

public:
	// constructor to create the initial adjacency matrix 
	MatrixGraph(T elements[], int size);

	// Function to insert a new edge 
	void addEdge(T start, T end, int weight);

	// Function to display the BFS traversal 
	void BFS(T start);

	void aStar(T start, T target);

	int kruskalMST(T cities[]);

	void displayGraph();
};

// Function to fill the empty adjacency matrix 
template <typename T>
MatrixGraph<T>::MatrixGraph(T elements[], int size)
{
	this->numVertices = size;
	vertices = new Vertex<T>[size];
	adj = new int*[numVertices];
	for (int row = 0; row < numVertices; row++)
	{
		adj[row] = new int[numVertices];
		vertices[row].vertex = elements[row];
		for (int column = 0; column < numVertices; column++)
		{
			adj[row][column] = 0;
		}
	}
}

// Function to add an edge to the MatrixGraph
template <typename T>
void MatrixGraph<T>::addEdge(T start, T end, int weight)
{
	int startID = 0;
	int endID = 0;

	for (int i = 0; i < numVertices; i++)
	{
		if (start == vertices[i].vertex)
		{
			startID = i;
		}
		if (end == vertices[i].vertex)
		{
			endID = i;
		}
	}
	// Considering a bidirectional edge 
	adj[startID][endID] = 1;
	adj[endID][startID] = 1;

	Edge<T> edgeForward = { start, end, weight };
	Edge<T> edgeBackward = { end, start, weight };

	vertices[startID].edges.push_back(edgeForward);
	vertices[endID].edges.push_back(edgeBackward);

	edges.push_back(make_pair( weight, make_pair(startID, endID)));

	vertices[startID].edges.back().pEndVertex = &vertices[endID];
	vertices[endID].edges.back().pEndVertex = &vertices[startID];
}

// Function to perform BFS on the MatrixGraph
template <typename T>
void MatrixGraph<T>::BFS(T start)
{
	int dTotal = 0;
	int cTotal = 0;

	// Visited vector to so that 
	// a vertex is not visited more than once 
	// Initializing the vector to false as no 
	// vertex is visited at the beginning 
	vector<bool> visited(numVertices, false);
	vector<int> q;
	list<Vertex<T>> queue;

	// find starting index location
	int id = 0;
	for (int i = 0; i < numVertices; i++)
	{
		if (start == vertices[i].vertex)
		{
			vertices[i].depth = 0;
			id = i;
		}
	}

	q.push_back(id);
	queue.push_back(vertices[id]);

	// Set source as visited 
	visited[id] = true;

	int vis;
	while (!q.empty()) 
	{
		start = queue.front().vertex;
		queue.pop_front();
		vis = q[0];

		for (int i = 0; i < numVertices; i++)
		{
			if (start == vertices[i].vertex)
			{
				id = i;
			}
		}

		// Print the current node 
		q.erase(q.begin());

		int numVisited = 0;
		// For every adjacent vertex to the current vertex
		for (int i = 0; i < numVertices; i++)
		{
			if (adj[vis][i] == 1 && (!visited[i])) 
			{
				// Push the adjacent node to the queue 
				q.push_back(i);
				queue.push_back(vertices[i]);

				// Set that node to be visited
				visited[i] = true;

				// set parent vertex
				vertices[i].parent = &vertices[id];

				// assign the vertex a depth for edge comparison
				vertices[i].depth = vertices[id].depth + 1;

				// add to discovery distance
				dTotal += vertices[vis].edges[numVisited].weight;
				cout << "Discovery: " << vertices[vis].edges[numVisited].start << " --> " << vertices[vis].edges[numVisited].end
					<< " (" << vertices[vis].edges[numVisited].weight << ")\n";
				numVisited = numVisited + 1;
			}
			else if (adj[vis][i] == 1 && (visited[i]))
			{
				Vertex<T>* start = &vertices[vis];
				Vertex<T>* end = vertices[vis].edges[numVisited].pEndVertex;

				while (start->depth > end->depth)
				{
					start = start->parent;
				}
				while (end->depth > start->depth)
				{
					end = end->parent;
				}
				
				if (start->vertex == end->vertex)
				{
					cout << "Back Edge: " << vertices[vis].edges[numVisited].start << " --> " << vertices[vis].edges[numVisited].end
						<< " (" << vertices[vis].edges[numVisited].weight << ")\n";
				}
				else
				{
					cout << "Cross Edge: " << vertices[vis].edges[numVisited].start << " --> " << vertices[vis].edges[numVisited].end
						<< " (" << vertices[vis].edges[numVisited].weight << ")\n";
				}
				
				numVisited = numVisited + 1;
			}
		}
	}

	cout << "\nTotal distance traveled over discovery edges: " << dTotal << '\n';
}

template<typename T>
void MatrixGraph<T>::aStar(T start, T target)
{
	if (start == target)
	{
		cout << start << " --> " << target << ":\n\t"
			<< start << " (0) = 0\n\n";
		return;
	}

	vector<Vertex<T>> open;	// list of vertices set to be checked
	vector<Vertex<T>> closed;	// list of vertices already checked
	vector<Vertex<T>> path;	// vertices of the final path after target is found
	int startID;	// index of starting vertex

	for (int i = 0; i < numVertices; i++)
	{
		if (vertices[i].vertex == start)
			startID = i;
	}
	Vertex<T> currentNode = vertices[startID];
	do
	{
		closed.push_back(currentNode);
		for (int i = 0; i < currentNode.edges.size(); i++)
		{
			open.push_back(*currentNode.edges[i].pEndVertex);
			open[open.size() - 1].cost = currentNode.cost + currentNode.edges[i].weight;
			open[open.size() - 1].parent = new Vertex<T>(currentNode);
		}
		for (int i = 0; i < closed.size(); i++)
		{
			for (int j = 0; j < open.size(); j++)
			{
				if (closed[i].vertex == open[j].vertex)
				{
					open.erase(open.begin() + j);
					j--;
				}
			}
		}
		currentNode = open[0];
		for (int i = 1; i < open.size(); i++)
		{
			if (open[i].cost < currentNode.cost)
			{
				currentNode = open[i];
			}
		}
	} while (currentNode.vertex != target);

	// push the calculated path to the path vector
	path.push_back(currentNode);
	while (path[path.size() - 1].vertex != start)
	{
		path.push_back(*path[path.size() - 1].parent);
	}

	int totalDistance = 0;

	// display the A* path
	cout << start << " --> " << target << ": \n\t"
		<< path[path.size() - 1].vertex;

	for (int i = path.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j < path[i].edges.size(); j++)
		{
			if (path[i].edges[j].pEndVertex->vertex == path[i].parent->vertex)
			{
				cout << " --> " << path[i].vertex << " (" << path[i].edges[j].weight << ")";
				totalDistance += path[i].edges[j].weight;
			}
		}
	}
	
	cout << " = " << totalDistance << "\n\n";
}

template<typename T>
inline void MatrixGraph<T>::displayGraph()
{
	cout << "Here is the adjacency matrix:\n";
	cout << "    ";
	for (int i = 0; i < numVertices; i++)
	{
		cout << vertices[i].vertex.substr(0, 3) << " ";
	}
	cout << endl;
	for (int row = 0; row < numVertices; row++)
	{
		for (int col = 0; col < numVertices + 1; col++)
		{
			if (col == 0)
				cout << vertices[row].vertex.substr(0, 3);
			else
			{
				cout << " " << adj[row][col - 1] << " ";
			}
			cout << " ";
		}
		cout << endl;
	}
}

struct DisjointSets
{
	int *parent, *rnk;
	int n;

	DisjointSets(int n)
	{
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u)
	{
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}
	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else
			parent[x] = y;
		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

template<typename T>
inline int MatrixGraph<T>::kruskalMST(T cities[])
{
	int mst_wt = 0;
	sort(edges.begin(), edges.end());
	DisjointSets ds(numVertices);
	vector< pair<int, pair<int, int> > >::iterator it;

	for (auto it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if (set_u != set_v)
		{
			// Current edge will be in the MST
			// so print it
			cout << vertices[u].vertex << " -- " << vertices[v].vertex << ": " << it->first << endl;

			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}