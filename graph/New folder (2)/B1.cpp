#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<long>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2)
    {
        adjList[vertex1].push_back(vertex2);
        edgeCount++;
    }

    void bfs(vector<long> &result, long start)
    {
        queue<long> q;
        vector<bool> visited(vertexCount, false);
        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex])
                {
                    q.push(vertex);
                    visited[vertex] = true;
                    result.push_back(vertex);
                }
            }
        }
    }
};

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfs(neighbor, adjList, visited);
            }
        }
    }

    void countComponents(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);

        // Build the graph
        for (auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            // adjList[edge[1]].push_back(edge[0]);
        }

        dfs(0, adjList, visited);
    }
};

int main()
{
    vector<vector<int>> edges = {
        {0, 1}, {0, 7}, {1, 2}, {2, 4}, {3, 7}, {4, 3}, {4, 5}, {5, 6}, {6, 7}};
    graph g;
    g.init(8);
    g.add_edge(0, 1);
    g.add_edge(0, 7);
    g.add_edge(1, 2);
    g.add_edge(2, 4);
    g.add_edge(4, 3);
    g.add_edge(3, 7);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_edge(6, 7);

    vector<long> dfs_result, bfs_result;

    g.bfs(bfs_result, 0);
    cout << "BFS: ";
    for (auto it : bfs_result)
    {
        cout << it << " ";
    }
    cout << endl;

    Solution mygraph;
    vector<vector<int>> edgestwo = {
        {0, 1}, {0, 7}, {1, 2}, {2, 4}, {3, 7}, {4, 3}, {4, 5}, {5, 6}, {6, 7}};
    int n = 8;
    cout << "DFS: ";
    mygraph.countComponents(n, edgestwo);

    return 0;
}