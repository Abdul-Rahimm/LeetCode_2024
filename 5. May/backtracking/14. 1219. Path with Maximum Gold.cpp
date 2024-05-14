// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int m, n;
vector<vector<int>> grid;
vector<vi> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int backtrack(int i, int j, int maximum, int total)
{
    // mark current cell visited
    int currentCell = grid[i][j];
    grid[i][j] = -1;

    for (auto dir : directions)
    {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] != -1 && grid[new_i][new_j] != 0)
            maximum = max(backtrack(new_i, new_j, maximum, total) + currentCell, maximum);
    }

    // unmark
    grid[i][j] = currentCell;

    return maximum;
}

int getMaximumGold(vector<vector<int>> &g)
{
    grid = g;

    m = grid.size();
    n = grid[0].size();
    int maximum = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] > 0)
                maximum = max(maximum, backtrack(i, j, maximum, 0));
        }
    }

    return maximum;
}

int main()
{
    vector<vector<int>> g{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << getMaximumGold(g) << endl;
}