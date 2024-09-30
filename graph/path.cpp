#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
            return true;

        // Step 1: Create the adjacency list
        vector<vector<int>> graph(n);
        for (const auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u); // Because the graph is undirected
        }

        // Step 2: Initialize BFS
        queue<int> q;
        vector<bool> visited(n, false);
        vector<int> parent(n, -1); // To store the path
        q.push(source);
        visited[source] = true;

        // Step 3: Perform BFS
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Check all adjacent nodes
            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    parent[neighbor] = node; // Record the parent for backtracking
                    if (neighbor == destination)
                    {
                        printPath(parent, source, destination);
                        return true;
                    }
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        // If BFS completes without finding the destination
        return false;
    }

private:
    void printPath(const vector<int> &parent, int source, int destination)
    {
        vector<int> path;
        int curr = destination;
        while (curr != -1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        cout << "Path from " << source << " to " << destination << ": ";
        for (int i = path.size() - 1; i >= 0; --i)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0, destination = 2;

    Solution sol;
    bool isPathValid = sol.validPath(n, edges, source, destination);

    cout << "Is there a valid path from source to destination? " << (isPathValid ? "Yes" : "No") << endl;

    return 0;
}
