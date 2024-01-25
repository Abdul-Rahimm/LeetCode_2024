// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string s1, s2;
int n, m;
int dp[1001][1001];

int solve(int i, int j)
{

    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    char a = s1[i];
    char b = s2[j];

    // if the char matches
    if (a == b)
    {
        return dp[i][j] = 1 + solve(i + 1, j + 1);
    }

    // if it doesnt match
    int takeI = solve(i + 1, j);
    int takeJ = solve(i, j + 1);

    return dp[i][j] = max(takeI, takeJ);
}

int longestCommonSubsequence(string text1, string text2)
{

    s1 = text1;
    s2 = text2;
    n = s1.size();
    m = s2.size();
    memset(dp, -1, sizeof(dp));

    return solve(0, 0);
}