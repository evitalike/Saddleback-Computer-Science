// C++ implementation of the approach 
#include <vector> 
#include <iostream>
#include <string>
#include <list>
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
	Vertex<T>* endPtr;
};

template <typename T>
struct Vertex
{
	T vertex;
	vector<Edge<T>> edges;
	int depth;
	Vertex<T>* parent;
};

template <typename T>
class MatrixGraph 
{
	// Number of vertex 
	int v;

	// Number of edges 
	int e;

	// Adjacency matrix
	int** adj;

	// Vertices of the graph
	Vertex<T>* vertices;

public:
	// To create the initial adjacency matrix 
	MatrixGraph(T elements[], int size);

	// Function to insert a new edge 
	void addEdge(T start, T end, int weight);

	// Function to display the BFS traversal 
	void BFS(T start);
};

// Function to fill the empty adjacency matrix 
template <typename T>
MatrixGraph<T>::MatrixGraph(T elements[], int size)
{
	this->v = size;
	vertices = new Vertex<T>[size];
	adj = new int*[v];
	for (int row = 0; row < v; row++) 
	{
		adj[row] = new int[v];
		vertices[row].vertex = elements[row];
		for (int column = 0; column < v; column++) 
		{
			adj[row][column] = 0;
		}
	}
}

// Function to add an edge to the MatrixGraph
template <typename T>
void MatrixGraph<T>::addEdge(T start, T end, int weight)
{
	int s = 0;
	int e = 0;

	for (int i = 0; i < v; i++)
	{
		if (start == vertices[i].vertex)
		{
			s = i;
		}
		if (end == vertices[i].vertex)
		{
			e = i;
		}
	}
	// Considering a bidirectional edge 
	adj[s][e] = 1;
	//adj[e][s] = 1;

	Edge<T> edgeForward = { start, end, weight };
	//Edge<T> edgeBackward = { end, start, weight };

	vertices[s].edges.push_back(edgeForward);
	//vertices[e].edges.push_back(edgeBackward);

	vertices[s].edges.back().endPtr = &vertices[e];
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
	vector<bool> visited(v, false);
	vector<int> q;
	list<Vertex<T>> queue;

	// find starting index location
	int id = 0;
	for (int i = 0; i < v; i++)
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

		for (int i = 0; i < v; i++)
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
		for (int i = 0; i < v; i++) 
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
				Vertex<T>* end = vertices[vis].edges[numVisited].endPtr;

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

	cout << endl;
	cout << "Here is the adjacency matrix:\n";
	cout << "    ";
	for (int i = 0; i < v; i++)
		cout << vertices[i].vertex.substr(0, 4) << " ";
	cout << endl;
	for (int row = 0; row < v; row++)
	{
		for (int col = 0; col < v + 1; col++)
		{
			if (col == 0)
				cout << vertices[row].vertex.substr(0, 4);
			else
			{
				cout << " " << adj[row][col - 1] << "  ";
			}
			cout << " ";
		}
		cout << endl;
	}
}