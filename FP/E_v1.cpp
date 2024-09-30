#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int customProcess(vector<int> &array, int left, int right, bool findMax)
{
    if (left == right)
    {
        return array[left];
    }

    int mid = left + (right - left) / 2;

    int leftResult = customProcess(array, left, mid, !findMax);
    int rightResult = customProcess(array, mid + 1, right, !findMax);

    return findMax ? max(leftResult, rightResult) : min(leftResult, rightResult);
}

int main()
{
    int n, inp;
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        array.push_back(inp);
    }

    bool findMax = true;
    int result = customProcess(array, 0, n - 1, findMax);

    cout << result << endl;

    return 0;
}
