// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<vector<int>> mat;
int rows, cols;
int dp[101][101];

int solve(int row, int col)
{
    if (row >= rows || col >= cols || row < 0 || col < 0)
        return 10000;
    if (dp[row][col] != -1)
        return dp[row][col];

    int take = mat[row][col] + min(solve(row + 1, col - 1), min(solve(row + 1, col), solve(row + 1, col - 1)));

    int ntake = col >= cols ? solve(row + 1, 0) : solve(row, col + 1); // skip to next number

    return dp[row][col] = min(take, ntake);
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    mat = matrix;
    rows = matrix.size();
    cols = matrix[0].size();
    memset(dp, -1, sizeof(dp));

    return solve(0, 0);
}

int main()
{
    vii nums{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(nums) << endl;
}