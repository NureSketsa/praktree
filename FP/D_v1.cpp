#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int MOD = 1000000007;
int main(int argc, char const *argv[])
{
    long long input, done = 1;

    cin >> input;
    // cout << input << endl;
    for (long long i = input; i != 0; i--)
    {
        // cout << i;
        done = done * i;
        done = done % MOD;
        // cout << " done " << done << endl;
    }

    cout << done;
}