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
                if (!visited[vertex])
                    st.push(vertex);
            }
        }
    }
    int rotarion = 0;

    int bfs(vector<long> &result, long start)
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
                if (visited[vertex])
                {
                    // cout << vertex << "add" << endl;
                    rotarion++;
                }

                if (!visited[vertex])
                {
                    q.push(vertex);
                    visited[vertex] = true;
                    // rotarion++;
                    result.push_back(vertex);
                }
            }
        }
        return rotarion;
    }
};

int main()
{
    graph g;
    int n, loop, terbesar = 0;
    cin >> loop;

    g.init(100);

    int x, y;
    for (int i = 0; i < loop; i++)
    {
        cin >> x >> y;
        g.add_edge(x - 1, y - 1);
    }

    vector<long> dfs_result, bfs_result;

    if (g.bfs(bfs_result, 0) >= 1)
    {
        cout << "Semak-semak";
    }
    else
    {
        cout << "Pohon";
    }

    return 0;
}