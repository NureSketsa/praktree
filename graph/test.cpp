#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution
{
public:
    int Sizegrid(vector<vector<int>> &grid)
    {
        // int n = grid[0].size();
        int n = grid.size();
        return n;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
    };
    cout << "Size : " << solution.Sizegrid(grid) << " " << INT_MAX << endl;
    return 0;
}