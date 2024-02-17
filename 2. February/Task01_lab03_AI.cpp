#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void countDirty(vector<vector<char>> &maze, int &count)
{
    for (vector<char> row : maze)
    {
        for (char i : row)
        {
            if (i == 'd')
                count++;
        }
    }
}
void print(vector<vector<char>> &maze, int i, int j)
{
    maze[i][j] = '*';

    for (vector<char> row : maze)
    {
        for (char i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
bool isSafe(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve(vector<vector<char>> &maze, int i, int j, int count, vector<vector<bool>> &vis)
{
    if (count == 0)
    {
        cout << "All cells have been marked clean" << endl;
        return;
    }
    // mark the current cell as visited
    vis[i][j] = true;
    if (maze[i][j] == 'd')
        maze[i][j] = 'c';

    // explore all directions from this block
    // change to c if required

    for (vector<int> dir : directions)
    {
        int newRow = i + dir[0];
        int newCol = j + dir[1];

        if (isSafe(newRow, newCol) && !vis[newRow][newCol] && maze[newRow][newCol] == 'd')
        {
            solve(maze, newRow, newCol, count - 1, vis);
        }
    }

    // returning from cell so mark it unvisited
    vis[i][j] = false;
}

int main()
{
    fastio;

    int dirty = 0;
    vector<vector<char>> maze{
        {'d', 'd', 'd', 'd', 'd', 'd', 'd', 'b'},
        {'b', 'b', 'c', 'd', 'b', 'b', 'b', 'b'},
        {'d', 'd', 'c', 'd', 'b', 'd', 'd', 'd'},
        {'d', 'd', 'd', 'd', 'c', 'c', 'c', 'd'},
        {'d', 'd', 'd', 'd', 'd', 'd', 'd', 'd'},
        {'d', 'd', 'd', 'd', 'd', 'd', 'd', 'd'},
        {'d', 'd', 'd', 'b', 'b', 'd', 'd', 'd'}};

    n = maze.size();
    m = maze[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    countDirty(maze, dirty);
    solve(maze, 0, 0, dirty, vis);
    print(maze, 0, 0);

    return 0;
}