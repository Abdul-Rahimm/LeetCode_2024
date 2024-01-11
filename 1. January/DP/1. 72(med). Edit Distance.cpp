// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[501][501];

int solve(int i, int j, string x, string y)
{
    // base cases
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    // match
    if (x[i] == y[j])
    {
        return dp[i][j] = solve(i - 1, j - 1, x, y);
    }

    // not match
    // 3 cases

    int insert = 1 + solve(i, j - 1, x, y);
    int del = 1 + solve(i - 1, j, x, y);
    int replace = 1 + solve(i - 1, j - 1, x, y);

    return dp[i][j] = min(replace, (min(insert, del)));
}

int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    memset(dp, -1, sizeof(dp));

    return solve(n - 1, m - 1, word1, word2);
}