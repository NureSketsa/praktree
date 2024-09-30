#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
#define ull unsigned long long

struct CustomCompare
{
    bool operator()(const pair<ull, ull> &lhs, const pair<ull, ull> &rhs)
    {
        if (lhs.first == rhs.first)
        {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    }
};

int main()
{
    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, CustomCompare> pq;
        ull enemy_count;
        cin >> enemy_count;
        ull x, y;

        for (ull i = 0; i < enemy_count; i++)
        {
            cin >> x >> y;
            pq.push(make_pair(x, y));
        }

        ull death_count = 0, score = 0;
        unordered_map<ull, ull> marked;

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            // Check if the current enemy has been marked
            if (marked[top.first] < top.first)
            {
                score += top.second;
                marked[top.first]++;
            }
            else
            {
                // Skip enemies that have already been marked the required number of times
                death_count++;
            }

            // Remove dead enemies directly from the priority queue
            while (!pq.empty() && marked.count(pq.top().first) && marked[pq.top().first] == pq.top().first)
            {
                pq.pop();
            }
        }

        cout << "Duarr skor maksimumnya " << score << endl;
    }

    return 0;
}
