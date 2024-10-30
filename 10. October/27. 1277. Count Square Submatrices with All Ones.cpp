// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n, m;
int dp[301][301];
int solve(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solve(i, j + 1, grid);
    int diag = solve(i + 1, j + 1, grid);
    int down = solve(i + 1, j, grid);

    return dp[i][j] = 1 + min(right, min(diag, down));
}
int countSquares(vector<vector<int>> &grid)
{
    n = grid.size();
    m = grid[0].size();
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                ans += solve(i, j, grid);
        }
    }

    return ans;
}

int countSquares_Tabulation(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    int ans = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i + 1][j + 1] = 1 + min({dp[i][j + 1], dp[i + 1][j], dp[i][j]});
                ans += dp[i + 1][j + 1];
            }
        }
    }

    return ans;
}