#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;

    void init(long v)
    {
        vertexCount = v;
        edgeCount = 0;

        for (int i = 0; i < vertexCount; i++)
        {
            adjList.push_back({}); // inserts V ammount of empty vector
        }
    }

    void add_edge(long vertex1, long vertex2, long weight)
    {
        adjList[vertex1].push_back(make_pair(vertex2, weight));
        adjList[vertex2].push_back(make_pair(vertex1, weight));
        edgeCount++;
    }

    void dijkstra(vector<long> &result, long start)
    {
        vector<long> pass(vertexCount, -1);
        vector<bool> visited(vertexCount, false);
        priority_queue<pair<long, long>,
                       vector<pair<long, long>>,
                       greater<pair<long, long>>>
            pq;
        result = vector<long>(vertexCount, LONG_MAX);

        pq.push(make_pair(0, start));
        result[start] = 0;

        while (!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            visited[temp.second] = true;

            for (auto vertex : adjList[temp.second])
            {
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if (!visited[nextVertex])
                {
                    if (temp.first + weight < result[nextVertex])
                    {
                        pass[nextVertex] = temp.second;
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                    }
                }
            }
        }

        vector<vector<pair<long, long>>> path;

        // for (auto vertex : pass)
        // {
        //     cout << vertex << " this vertex" << endl;
        // }

        for (long i = 0; i < vertexCount; i++)
        {
            // cout << result[i] << endl;

            if (pass[i] == -1 || result[i] == LONG_MAX)
            {
                cout << "0 to " << i << " have no path" << endl;
                continue;
            }

            int help = i;
            while (help != 0)
            {
                cout << help << ", ";
                help = pass[help];
            }
            cout << 0 << " ";
            cout << endl;
        }
    }
};

int main()
{
    graph g;
    g.init(7);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 4, 100);
    g.add_edge(0, 3, 30);
    g.add_edge(1, 2, 50);
    g.add_edge(2, 3, 20);
    g.add_edge(2, 4, 10);
    g.add_edge(3, 4, 60);

    g.add_edge(5, 6, 60);

    vector<long> dijkstra_result;

    g.dijkstra(dijkstra_result, 0);

    // for (int i = 0; i < dijkstra_result.size(); i++)
    // {
    //     cout << i << " " << dijkstra_result[i] << endl;
    // }

    return 0;
}