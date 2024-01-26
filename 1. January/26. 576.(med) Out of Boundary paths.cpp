// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int m, n;
int MOD = 1e9 + 7;
int dp[51][51][51];

vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solve(int moves, int row, int col)
{

    if (moves >= 0 && (row < 0 || row >= m || col < 0 || col >= n))
        return 1;
    if (moves < 0)
        return 0;
    if (dp[moves][row][col] != -1)
        return dp[moves][row][col];

    int north = solve(moves - 1, row + dir[0][0], col + dir[0][1]);

    int east = solve(moves - 1, row + dir[1][0], col + dir[1][1]);

    int south = solve(moves - 1, row + dir[2][0], col + dir[2][1]);

    int west = solve(moves - 1, row + dir[3][0], col + dir[3][1]);

    int ans = 0;

    ans = (ans + north) % MOD;
    ans = (ans + east) % MOD;
    ans = (ans + south) % MOD;
    ans = (ans + west) % MOD;

    return dp[moves][row][col] = ans;

    //         vector<int> level(4, 0);
    //         int i = 0;

    //         for(vector<int> direction : dir){
    //             int x = direction[0];
    //             int y = direction[1];

    //             //new place to go
    //             int newX = row + x;
    //             int newY = row + y;

    //             return level[i++] = solve(moves - 1, newX, newY);
    //         }

    // return accumulate(level.begin(), level.end(), 0);
}

int findPaths(int x, int y, int maxMove, int startRow, int startColumn)
{

    m = x;
    n = y;
    memset(dp, -1, sizeof(dp));

    return solve(maxMove, startRow, startColumn);
}