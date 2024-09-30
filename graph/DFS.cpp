#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// DFS It's often used
// to explore all the nodes and edges of a graph.

class Solution
{
public:
    int rotation = 0;
    void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        cout << "we on node:" << (node + 1) << endl;
        // if (node == 0)
        // {
        //     rotation++;
        // }

        visited[node] = true;
        for (int neighbor : adjList[node])
        {
            cout << "we on neighbor:" << (neighbor + 1) << endl;
            if (visited[neighbor])
            {
                rotation++;
            }

            if (!visited[neighbor])
            {
                dfs(neighbor, adjList, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        // Build the graph
        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adjList, visited);
                count++;
            }
        }
        cout << rotation << endl;
        return rotation;
    }
};

int main()
{
    Solution mygraph;
    int n, loop, terbesar = 0;
    cin >> loop;

    vector<vector<int>> edges;

    int x, y;
    for (int i = 0; i < loop; i++)
    {
        cin >> x >> y;
        edges.push_back({x - 1, y - 1});
        // g.add_edge(y - 1, x - 1, weight);

        if (terbesar <= x)
        {
            terbesar = x;
        }
        if (terbesar <= y)
        {
            terbesar = y;
        }
    }

    if (mygraph.countComponents(terbesar, edges) >= 3)
    {
        printf("Pohon");
    }
    else
    {
        printf("Semak-semak");
    }

    // mygraph.countComponents(n, edges);
    return 0;
}

// g.addEdge(0, 1);
// g.addEdge(1, 2);
// g.addEdge(3, 1);
// g.addEdge(3, 4);
// g.addEdge(4, 2);