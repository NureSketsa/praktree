#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int kruskalMST(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end());
    UnionFind uf(n);

    int totalWeight = 0;
    for (const Edge &edge : edges)
    {
        if (uf.find(edge.u) != uf.find(edge.v))
        {
            uf.unionSets(edge.u, edge.v);
            totalWeight += edge.weight;
        }
    }

    return totalWeight;
}

int main()
{
    int n = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7}};

    int totalWeight = kruskalMST(n, edges);
    cout << "Total weight of the MST: " << totalWeight << endl;

    return 0;
}
