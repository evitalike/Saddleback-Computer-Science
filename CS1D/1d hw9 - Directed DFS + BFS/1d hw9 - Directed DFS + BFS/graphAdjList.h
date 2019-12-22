#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

const int LIST_SIZE = 12;

enum Cities
{
    Chicago, Seattle, Boston, Denver, Houston, LosAngeles,
    KansasCity, Atlanta, Dallas, Miami, SanFrancisco, NewYork
};

struct graph{
    std::vector<std::pair<int,int>> adjL;
    std::string name;
    int startTime = 0;
    int endTime = 0;
};

std::string findName(int i);

class graphAdjList
{
    public:
        graphAdjList(graph *g);
        graphAdjList();
        void addEdge( int v1, int v2, int distance );
        void DFS1();
        void checkConnection();
        void printGraph();
        void sortByDist();
        
    
    private:
        void check_con_DFS(int u, std::vector<bool> &visited);
        void DFS2(int u, std::vector<bool> &visited,
                        std::vector<std::string>& discEdges, std::vector<std::string>& backEdges,
                        std::vector<std::string>& forwardEdges, std::vector<std::string>& crossEdges);
        graph *reverseEdges();

        int numVerts = 0;
        int numEdges = 0;
        int deDist = 0;
        int beDist = 0;
        int t = 0;
        graph *g;
};

void graphAdjList::addEdge( int v1, int v2, int distance )
{
    g[v1].adjL.push_back(std::make_pair(v2,distance));
    g[v1].name = findName(v1);
}

std::string findName( int i )
{
    switch(i)
    {
        case Chicago: return "Chicago";
        case Seattle: return "Seattle";
        case Boston: return "Boston";
        case SanFrancisco: return "San Francisco";
        case NewYork: return "New York";
        case LosAngeles: return "Los Angeles";
        case Denver: return "Denver";
        case KansasCity: return "Kansas City";
        case Atlanta: return "Atlanta";
        case Dallas: return "Dallas";
        case Houston: return "Houston";
        case Miami: return "Miami";
    }
    return "NA";
}

graphAdjList::graphAdjList()
{
    g = new graph[LIST_SIZE];
}

graphAdjList::graphAdjList(graph *newG)
{
    g = newG;
}

// Print adjacency list representaion ot graph 
void graphAdjList::printGraph() 
{ 
    std::string s; 
    int w; 
    for (int u = 0; u < LIST_SIZE; u++) 
    { 
        std::cout << "Node " << g[u].name << " makes an edge with \n"; 
        for (auto it = g[u].adjL.begin(); it!=g[u].adjL.end(); it++) 
        { 
            s = findName(it->first); 
            w = it->second; 
            std::cout << "\tNode " << s << " with weight = "
                 << w << "\n"; 
        } 
        std::cout << "\n"; 
    } 
}

graph *graphAdjList::reverseEdges()
{
    graph *t = new graph[LIST_SIZE];
    for(int i=0; i< LIST_SIZE; i++)
    {
        for(std::vector<std::pair<int, int>>::iterator j = g[i].adjL.begin(); j != g[i].adjL.end(); j++)
        {
            t[j->first].adjL.push_back(std::make_pair(i, j->second));
            t[j->first].name = findName(j->first);
        }
    }
    return t;
}

void graphAdjList::checkConnection()
{
    std::vector<bool> visited(LIST_SIZE, false);
    check_con_DFS(0, visited);
    bool connected = true;
    for(std::vector<bool>::iterator i = visited.begin(); i!=visited.end(); i++)
    {
        if(!*i)
            connected = false;
    }
    for(std::vector<bool>::iterator i = visited.begin(); i!=visited.end(); i++)
    {
        *i = false;
    }
    if(connected)
    {
        graphAdjList g2(this->reverseEdges());
        g2.printGraph();
        g2.check_con_DFS(0, visited);
        for(std::vector<bool>::iterator i = visited.begin(); i!=visited.end(); i++)
        {
            if(!*i)
                connected = false;
        }
    }
    if(connected)
    {
        std::cout << "\nThe graph is strongly connected, as all nodes can \nbe accessed no matter which node the traversal starts on.\n";
    }
    else
    {
        std::cout << "\nThe graph is not strongly connected\n";
    }
    
}

struct comparator {
  bool operator() (std::pair<int,int> i, std::pair<int,int> j) 
  { return (i.second<j.second);}
} lessthan;

void graphAdjList::sortByDist()
{
    for(int i = 0; i < LIST_SIZE; i++)
    {
        std::sort(g[i].adjL.begin(), g[i].adjL.end(), lessthan);
    }
}

// A utility function to do DFS of graph 
// recursively from a given vertex u. 
void graphAdjList::DFS2(int u, std::vector<bool> &visited,
                        std::vector<std::string>& discEdges, std::vector<std::string>& backEdges,
                        std::vector<std::string>& forwardEdges, std::vector<std::string>& crossEdges) 
{
    std::string edge;
    visited[u] = true;
    t++;
    g[u].startTime += t;
    for (int i=0; i < g[u].adjL.size(); i++)
    {
        if (!visited[g[u].adjL.at(i).first])
        {
            deDist += g[u].adjL.at(i).second;
            edge = findName(u);
            edge += " -> ";
            edge += findName(g[u].adjL.at(i).first);
            discEdges.push_back(edge);
            std::cout << std::endl <<findName(u) << " -> " << findName(g[u].adjL.at(i).first) << " ("<<deDist<<") " <<std::endl;
            DFS2(g[u].adjL.at(i).first, visited, discEdges, backEdges, forwardEdges, crossEdges);
            
        }
        else
        {
            edge = findName(u);
            edge += " -> ";
            edge += findName(g[u].adjL.at(i).first);
            
            if(g[g[u].adjL.at(i).first].endTime == 0)
            {
                backEdges.push_back(edge);
            }
            else if(g[u].startTime > g[g[u].adjL.at(i).first].startTime)
            {
                crossEdges.push_back(edge);
            }
            else
            {
                forwardEdges.push_back(edge);
            }
            
        }
    }
    t+=1;
    g[u].endTime += t;
}

void graphAdjList::check_con_DFS(int u, std::vector<bool> &visited) 
{
    visited[u] = true;
    for (int i=0; i < g[u].adjL.size(); i++)
    {
        if (!visited[g[u].adjL.at(i).first])
        {
            check_con_DFS(g[u].adjL.at(i).first, visited);
        }
    }
}

// This function does DFSUtil() for all  
// unvisited vertices. 
void graphAdjList::DFS1() 
{ 
    std::vector<bool> visited(LIST_SIZE, false);
    std::vector<std::string> discEdges;
    std::vector<std::string> backEdges;
    std::vector<std::string> forwardEdges;
    std::vector<std::string> crossEdges; 
    DFS2(0, visited, discEdges, backEdges, forwardEdges, crossEdges);
    std::cout << std::endl << "DISCOVERY DISTANCE: " << deDist << std::endl <<std::endl;
    std::cout << "DISCOVERY EDGES:\n";
    for(std::vector<std::string>::iterator de = discEdges.begin(); de!=discEdges.end(); de++)
    {
        std::cout << "(" << *de << ") \n";
    }
    std::cout << "\nBACK EDGES:\n";
    for(std::vector<std::string>::iterator be = backEdges.begin(); be!=backEdges.end(); be++)
    {
        std::cout << "(" << *be << ") \n";
    }
    std::cout << "\nFORWARD EDGES:\n";
    for(std::vector<std::string>::iterator fe = forwardEdges.begin(); fe!=forwardEdges.end(); fe++)
    {
        std::cout << "(" << *fe << ") \n";
    }
    std::cout << "\nCROSS EDGES:\n";
    for(std::vector<std::string>::iterator ce = crossEdges.begin(); ce!=crossEdges.end(); ce++)
    {
        std::cout << "(" << *ce << ") \n";
    }
}