
#include <bits/stdc++.h>
using namespace std;

struct graph
{
    long vertexCount, edgeCount;
    vector<vector<pair<long, long>>> adjList;
    vector<pair<long, pair<long, long>>> edgeList;

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

        edgeList.push_back(make_pair(weight, make_pair(vertex1, vertex2)));
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

            if (visited[temp.second])
                continue;

            visited[temp.second] = true;

            for (auto vertex : adjList[temp.second])
            {
                long nextVertex = vertex.first;
                long weight = vertex.second;

                if (temp.first + weight < result[nextVertex])
                {
                    result[nextVertex] = temp.first + weight;
                    pq.push(make_pair(result[nextVertex], nextVertex));
                }
            }
        }
    }

    long find_parent(vector<long> &parent, long v)
    {
        if (v == parent[v])
            return v;

        return find_parent(parent, parent[v]);
    }

    void union_set(vector<long> &parent, long vertex1, long vertex2)
    {
        parent[vertex2] = parent[vertex1];
    }

    void kruskal(vector<pair<long, pair<long, long>>> &result)
    {
        vector<long> parent;
        for (int i = 0; i < vertexCount; i++)
            parent.push_back(i);

        sort(edgeList.begin(), edgeList.end());

        for (auto edge : edgeList)
        {
            long vertex1 = edge.second.first;
            long vertex2 = edge.second.second;
            if (find_parent(parent, vertex1) != find_parent(parent, vertex2))
            {
                result.push_back(edge);
                union_set(parent, vertex1, vertex2);
                if (result.size() == vertexCount - 1)
                    return;
            }
        }
    }
};

int main()
{
    int n, loop;
    cin >> n >> loop;

    graph g;
    graph g_two;
    g.init(n);
    // g_two.init(n);
    int x, y, weight;
    for (int i = 0; i < loop; i++)
    {
        cin >> x >> y >> weight;
        g.add_edge(x - 1, y - 1, weight);
        // g_two.add_edge(x - 1, y - 1, weight * 100);
    }

    vector<pair<long, pair<long, long>>> kruskal_result;

    int terberat = 0;

    g.kruskal(kruskal_result);

    for (auto it : kruskal_result)
    {
        if (terberat <= it.first)
        {
            terberat = it.first;
        }

        // cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    }

    cout << terberat;

    return 0;
}
