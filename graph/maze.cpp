#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, m, option;
pair<int, int> start, finish;
vector<vector<char>> grid(20, vector<char>(20));
vector<vector<int>> vis(20, vector<int>(20, 0));
bool isPossibleS = false;
bool isPossibleE = false;
vector<vector<char>> path(20, vector<char>(20));
char direction[4] = {'R', 'L', 'U', 'D'};
int moves[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#');
}

void pathTracing(int x, int y)
{
    if (grid[x][y] == 'S')
        return;
    char dir = path[x][y];
    grid[x][y] = 'x';
    switch (dir)
    {
    case 'U':
        pathTracing(x + 1, y);
        break;
    case 'D':
        pathTracing(x - 1, y);
        break;
    case 'R':
        pathTracing(x, y - 1);
        break;
    case 'L':
        pathTracing(x, y + 1);
        break;
    }
}

void makeGrid()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                start = make_pair(i, j);
                isPossibleS = true;
            }
            if (grid[i][j] == 'E')
            {
                finish = make_pair(i, j);
                isPossibleE = true;
            }
        }
    }
}

void makeRandomGrid()
{
    srand(time(0)); // Seed for random number generation

    int totalCells = m * n;
    int numWalls = totalCells * 30 / 100;
    int numOpen = totalCells - numWalls;

    vector<char> cells;
    for (int i = 0; i < numWalls; i++)
        cells.push_back('#');
    for (int i = 0; i < numOpen; i++)
        cells.push_back('.');

    // Shuffle the cells to randomize the distribution
    random_shuffle(cells.begin(), cells.end());

    // Populate the grid with the shuffled cells
    int index = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = cells[index++];
        }
    }

    // Set the start and end points
    grid[0][0] = 'S';
    start = make_pair(0, 0);
    isPossibleS = true;

    grid[m - 1][n - 1] = 'E';
    finish = make_pair(m - 1, n - 1);
    isPossibleE = true;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }

    if (grid[0][1] == '#' && grid[1][0] == '#')
    {
        isPossibleS = false;
    }

    if (grid[m - 2][n - 1] == '#' && grid[m - 2][n - 1] == '#')
    {
        isPossibleE = false;
    }
}

void findPath()
{
    if (!isPossibleE)
    {
        cout << "tujuan tidak ditemukan\n";
        return;
    }

    if (!isPossibleS)
    {
        return;
    }

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    while (!q.empty())
    {
        auto [currentX, currentY] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = currentX + moves[i][0];
            int y = currentY + moves[i][1];
            if (isValid(x, y) && !vis[x][y])
            {
                vis[x][y] = 1;
                q.push(make_pair(x, y));
                path[x][y] = direction[i];
                if (grid[x][y] == 'E')
                {
                    pathTracing(x - moves[i][0], y - moves[i][1]);
                    for (int i = 0; i < m; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            cout << grid[i][j] << " ";
                        }
                        cout << "\n";
                    }
                    return;
                }
            }
        }
    }
    cout << "tujuan tidak ditemukan\n";
}

int main()
{
    cout << "X size : ";
    cin >> n;
    cout << "Y size : ";
    cin >> m;

    cout << "1 for make your own maze\n2 for random maze\n: ";
    cin >> option;
    if (option == 1)
    {
        makeGrid(); // MAKING GRID
    }
    else if (option == 2)
    {
        makeRandomGrid(); // random grid
    }

    cout << "{waiting for input}";
    cin >> option;

    cout << "PATH : \n";
    findPath(); // FINDING

    return 0;
}
