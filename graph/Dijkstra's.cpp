#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>> &graph, int start)
{
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{

    int test_set = 1, n, loop, k, e;

    cin >> n >> loop >> k >> e;
    vector<vector<pair<int, int>>> graph(n + 1);

    // cin >> n;

    int x, y, weight;
    for (int i = 0; i < loop; i++)
    {
        cin >> x >> y >> weight;
        graph[x].emplace_back(y, weight * k - 3);
        graph[y].emplace_back(x, weight);
    }

    vector<int> distances = dijkstra(n + 1, graph, 1);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < distances.size(); i++)
    {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
