#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int counter = 0;
    int size = 0;
    int terberat = 0;
    vector<int> v;
    void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        size++;
        visited[node] = true;
        // cout << node << " ";
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

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                size = 0;
                dfs(0, adjList, visited);
                v.push_back(size);
            }

            // dfs(0, adjList, visited);
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (terberat <= v[i])
            {
                terberat = v[i];
            }

            // cout << v[i] << std::endl;
        }
        cout << terberat << std::endl;
        // dfs(0, adjList, visited);
    }
};

int main()
{
    Solution mygraph;
    vector<vector<int>> edgestwo;
    int n, loop, x, y;

    cin >> n >> loop;

    for (int i = 0; i < loop; i++)
    {
        cin >> x >> y;
        edgestwo.push_back({x - 1, y - 1});
    }

    // cou;
    mygraph.countComponents(n, edgestwo);

    return 0;
}