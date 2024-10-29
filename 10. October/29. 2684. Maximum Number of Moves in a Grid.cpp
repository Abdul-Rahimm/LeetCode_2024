// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n, m;
int dp[1001][1001];
bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}
int solve(int i, int j, vector<vector<int>> &grid)
{
    if (!isValid(i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int take = 0;
    for (int x = -1; x <= 1; x++)
    {
        if (isValid(i + x, j + 1) && grid[i + x][j + 1] > grid[i][j])
            take = max(take, 1 + solve(i + x, j + 1, grid));
    }

    return dp[i][j] = take;
}

int maxMoves(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, solve(i, 0, grid));
    }

    return ans;
}