#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        visited[node] = true;
        for (int neighbor : adjList[node])
        {
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

        return count;
    }
};

int main()
{
    Solution solution;
    // vector<vector<int>> edges = {};
    // cout << "Number of connected components: " << solution.countComponents(n, edges) << endl;

    // map<string, int> nameIndex;

    int loop, loop_two, size, index = 0;
    cin >> loop;
    for (int i = 0; i < loop; i++)
    {
        vector<vector<int>> edges = {};
        map<string, int> nameIndex;
        index = 0;
        cin >> size >> loop_two;
        for (int j = 0; j < loop_two; j++)
        {
            string name1, name2;
            cin >> name1 >> name2;

            if (nameIndex.find(name1) == nameIndex.end())
            {
                nameIndex[name1] = index++;
            }
            if (nameIndex.find(name2) == nameIndex.end())
            {
                nameIndex[name2] = index++;
            }

            int idx1 = nameIndex[name1];
            int idx2 = nameIndex[name2];

            edges.push_back({idx1, idx2});
            // cout << idx1 << " " << idx2 << endl;
        }

        // cout << "edges " << solution.countComponents(size, edges) << endl;

        if (solution.countComponents(size, edges) <= 1)
        {
            cout << "Tidak Menyirkel" << endl;
        }
        else
        {
            cout << "Menyirkel" << endl;
        }

        // nameIndex.clear();
        // edges.clear();
    }

    return 0;
}
