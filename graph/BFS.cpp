#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        // vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark as visited

        int pathLength = 1;

        while (!q.empty())
        {
            int size = q.size(); // cek where to walk
            cout << "new while loop " << size << endl;
            for (int i = 0; i < size; i++)
            {
                auto [x, y] = q.front();
                cout << x + 1 << " " << y + 1 << endl;
                q.pop();

                // checkin if finish line
                if (x == n - 1 && y == n - 1)
                    return pathLength;

                for (auto dir : directions)
                {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if (newX >= 0 && newY >= 0   // if there path
                        && newX < n && newY < n  // out off grid
                        && grid[newX][newY] == 0 // cek if visible
                    )
                    {
                        q.push({newX, newY}); // new path
                        grid[newX][newY] = 1; // alreay visited
                    }
                }
            }
            pathLength++;
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}};
    cout << "Shortest Path Length: " << solution.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}
