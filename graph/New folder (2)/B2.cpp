#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

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

    int test_set, n, loop;

    cin >> test_set;

    for (int j = 0; j < test_set; j++)
    {
        cin >> n >> loop;
        vector<vector<pair<int, int>>> graph(n + 1);

        // cin >> n;

        int x, y, weight;
        for (int i = 0; i < loop; i++)
        {
            cin >> x >> y >> weight;
            graph[x].emplace_back(y, weight);
            graph[y].emplace_back(x, weight);
        }

        int home, dest;
        cin >> home >> dest;
        vector<int> distances = dijkstra(n + 1, graph, home);

        // cout << "Shortest distances from node " << home << ":" << endl;
        // cout << "Node " << dest << ": " << distances[dest] << endl;
        if (distances[dest] == 2147483647)
        {
            cout << "tersesat" << endl;
        }
        else
        {
            cout << distances[dest] << endl;
        }
    }

    return 0;
}
