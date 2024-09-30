#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Declare a priority queue to store pairs of (data: string, priority: long long)
    priority_queue<pair<string, long long>, vector<pair<string, long long>>, less<pair<string, long long>>> pq;

    // Push some pairs into the priority queue
    pq.push({"first", 10000000000LL}); // (string: "first", priority: 10000000000)
    pq.push({"second", 5000000000LL}); // (string: "second", priority: 5000000000)
    pq.push({"third", 15000000000LL}); // (string: "third", priority: 15000000000)

    // Extract elements from the priority queue
    while (!pq.empty())
    {
        pair<string, long long> top = pq.top();
        pq.pop();
        cout << "String: " << top.first << ", Priority: " << top.second << endl;
    }

    return 0;
}
