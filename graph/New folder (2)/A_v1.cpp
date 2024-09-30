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

    void dfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        stack<long> st;

        st.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!st.empty())
        {
            long temp = st.top();
            st.pop();

            if (!visited[temp])
            {
                result.push_back(temp);
                visited[temp] = true;
            }

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                    st.push(vertex.first);
            }
        }
    }

    void bfs(vector<long> &result, long start)
    {
        vector<bool> visited(vertexCount, false);
        queue<long> q;

        q.push(start);
        visited[start] = true;
        result.push_back(start);

        while (!q.empty())
        {
            long temp = q.front();
            q.pop();

            for (auto vertex : adjList[temp])
            {
                if (!visited[vertex.first])
                {
                    q.push(vertex.first);
                    visited[vertex.first] = true;
                    result.push_back(vertex.first);
                }
            }
        }
    }

    void dijkstra(vector<long> &result, long start)
    {
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
                        result[nextVertex] = temp.first + weight;
                        pq.push(make_pair(result[nextVertex], nextVertex));
                    }
                }
            }
        }
    }
};

int main()
{
    graph g;
    int test_set = 1, n, loop, k, e;
    g.init(6);

    cin >> n >> loop >> k >> e;
    int x, y, weight;

    // g.add_edge(0, 1, 2);

    g.init(n);

    for (int i = 0; i < loop; i++)
    {
        cin >> x >> y >> weight;
        g.add_edge(x - 1, y - 1, weight);
    }

    vector<long> dijkstra_result;

    // - k )* 3
    g.dijkstra(dijkstra_result, 0);

    if (((dijkstra_result[3] - k) * 3) < e)
    {
        cout << (dijkstra_result[3] - k) * 3 << endl;
    }
    else
    {
        cout << "muak gweh, butuh heal lagi" << endl;
    }

    return 0;
}