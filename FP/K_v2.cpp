#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <algorithm>

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

int main(int argc, char const *argv[])
{
    priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, CustomCompare> pq;

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {

        ull enemy_count;
        ull x, y;
        cin >> enemy_count;
        for (int i = 0; i < enemy_count; i++)
        {
            cin >> x >> y;
            pq.push(make_pair(x, y));
        }

        ull death_count = 0, marked_count = 0, score = 0, old_size;
        vector<ull> marked = {}, death = {};

        // cout << "GAMES: " << i << endl;
        while (death_count + marked_count != enemy_count)
        {
            // cout << endl
            //      << "new round " << endl;
            // cout << pq.top().first << " " << pq.top().second << endl;

            marked.push_back(pq.top().first);
            score += pq.top().second;
            pq.pop();

            marked_count = marked.size();

            if (marked_count == pq.top().first && !(pq.empty()) && (death_count + marked_count != enemy_count))
            {
                while (marked_count == pq.top().first && !(pq.empty()))
                {

                    // cout << "DEAD FROM PQ " << marked_count << " " << pq.top().first << " " << pq.top().second << endl;

                    pq.pop();
                    death_count++;
                }
            }

            if (std::find(marked.begin(), marked.end(), marked_count) != marked.end() && !(marked.empty()) && (death_count + marked_count != enemy_count))
            {
                // cout << "MARKED: ";
                // for (auto i = marked.begin(); i != marked.end(); ++i)
                //     cout << *i << " ";
                // cout << '\n';
                // cout << "DEAD FROM MARKED " << marked_count << endl;

                old_size = marked.size();
                marked.erase(std::remove(marked.begin(), marked.end(), marked_count), marked.end());
                death_count += old_size - marked.size();
                marked_count = marked.size();
            }

            // cout << "report " << marked_count << " " << death_count << " " << score << endl
            //  << endl;
        }

        cout << "Duarr skor maksimumnya " << score << endl;
    }
}
