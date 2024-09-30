#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    vector<vector<int>> adjList;

    Graph(int numVertices)
    {
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Comment this line for a directed graph
    }

    void printGraph()
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << "Vertex " << i << ":";
            for (int j = 0; j < adjList[i].size(); j++)
            {
                if (j == 0)
                {
                    cout << " -> " << adjList[i][j] << '\t' << endl;
                }
                else
                {
                    cout << "\t " << " -> " << adjList[i][j] << endl;
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, loop;

    cin >> n >> loop;

    Graph g(n + 1);
    int x, y;
    for (int i = 0; i < loop; i++)
    {
        g.addEdge(x, y);
    }

    g.printGraph();

    return 0;
}

// Graph: A graph is a non-linear
// data structure consisting of a set of vertices (nodes)
// and a set of edges (connections) that establish relationships
// between these vertices.

// Vertex (Node): A vertex is a fundamental unit of a graph,
//  often representing an entity or an object.
// Vertices are connected by edges.

// Edge: An edge is a connection between two vertices.
// It may have a direction (directed edge) or not (undirected edge).