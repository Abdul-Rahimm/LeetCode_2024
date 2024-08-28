// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;
int m;
vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool DFS(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{

    if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] == 0)
        return false;

    if (grid2[i][j] == 1 && grid1[i][j] == 0)
        return false;

    // already explored
    grid1[i][j] = 0;
    grid2[i][j] = 0;

    for (vector<int> dir : directions)
    {
        int new_x = dir[0];
        int new_y = dir[1];

        if (DFS(i + new_x, j + new_y, grid1, grid2))
            return true;
    }

    return false;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    n = grid1.size();
    m = grid1[0].size();
    int regions = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid2[i][j] == 1 && DFS(i, j, grid1, grid2) == true)
            {
                regions++;
            }
        }
    }

    return regions;
}

int main()
{
    vii grid1{{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
    vii grid2{{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
    int regions = countSubIslands(grid1, grid2);
    cout << regions << endl;
}