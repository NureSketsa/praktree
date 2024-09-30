#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct CustomCompare
{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++)
    {

        int enemy_count, x, y;
        cin >> enemy_count;
        for (int i = 0; i < enemy_count; i++)
        {
            cin >> x >> y;
            pq.push(make_pair(x, y));
        }

        int death_count = 0, marked_count = 0, score, temp_rem, old_size;
        vector<int> marked = {}, death = {};
        while (death_count + marked_count != enemy_count)
        {
            cout << endl
                 << "new round " << endl;
            cout << pq.top().first << " " << pq.top().second << endl;

            marked.push_back(pq.top().first);
            score += pq.top().second;
            pq.pop();

            death_count = death.size();
            marked_count = marked.size();

            if (marked_count == pq.top().first && !(pq.empty()))
            {
                temp_rem = pq.top().first;
                while (marked_count == pq.top().first && !(pq.empty()))
                {

                    cout << "DEAD FROM PQ " << marked_count << " " << pq.top().first << " " << pq.top().second << endl;

                    pq.pop();
                    death_count++;
                }
            }

            if (std::find(marked.begin(), marked.end(), marked_count) != marked.end() && !(marked.empty()))
            {
                cout << "MARKED: ";
                for (auto i = marked.begin(); i != marked.end(); ++i)
                    cout << *i << " ";
                cout << '\n';
                cout << "DEAD FROM MARKED " << marked_count << endl;

                old_size = marked.size();
                marked.erase(std::remove(marked.begin(), marked.end(), marked_count), marked.end());
                death_count += old_size - marked.size();
                marked_count = marked.size();
            }

            cout << "report " << marked_count << " " << death_count << " " << score << endl
                 << endl;
        }

        cout << score << endl;
    }
}
