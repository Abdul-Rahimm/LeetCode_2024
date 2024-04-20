// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int rows, cols;
vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void DFS(int i, int j, vector<vector<char>> &grid)
{

    // out of bound
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1')
        return;

    grid[i][j] = '$';

    // now explore all directions
    for (vector<int> dir : directions)
    {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        DFS(new_i, new_j, grid);
    }

    return;
}

int numIslands(vector<vector<char>> &grid)
{
    rows = grid.size();
    cols = grid[0].size();
    int score = 0;

    // vector<vector<bool>> visited(rows, vector<bool> (cols, false));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (grid[i][j] == '1')
            {
                DFS(i, j, grid);
                score++;
            }
        }
    }

    return score;
}

int main()
{
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
    };

    cout << numIslands(grid) << endl;
}