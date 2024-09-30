#include <bits/stdc++.h>
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

void solve()
{
    int musuh;
    cin >> musuh;

    priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, CustomCompare> pq;

    for (int i = 0; i < musuh; i++)
    {
        int markLimit, skor;
        cin >> markLimit >> skor;
        pq.push({markLimit, skor});
    }

    int limit = 1;
    int temp = -1;
    ull ans = 0;
    bool udahMasuk = false;

    // for (int i = 0; i < musuh; i++)
    // {
    //     cout << pq.top().first << " " << pq.top().second << endl;
    //     pq.pop();
    // }

    for (int i = 0; i < musuh; i++)
    {
        int marks = pq.top().first;
        int score = pq.top().second;
        pq.pop();
        // cout << marks << " " << score << endl;
        if (limit >= marks)
        {
            // cout << "popped at limit, currently limit at " << limit << endl;
            if (!udahMasuk)
            {
                // cout << " is getting to ans\n";
                ans += score;
                udahMasuk = true;
            }
            continue;
        }
        if (temp != marks)
        {
            udahMasuk = false;
            ans += score;
            temp = marks;
            limit = 1;
            // cout << "popped at temp, currently limit at " << limit << " and temp at " << temp << endl;
            continue;
        }

        udahMasuk = true;
        ans += score;
        limit++;
        // cout << "popped at else, currently limit at " << limit << endl;
    }

    cout << "Duarr skor maksimumnya " << ans << endl;
}

int main(int argc, char const *argv[])
{
    int t = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}