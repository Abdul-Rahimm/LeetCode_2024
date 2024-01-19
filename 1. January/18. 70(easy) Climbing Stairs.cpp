// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[47];

int solve(int n)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = solve(n - 1) + solve(n - 2);
}

int climbStairs(int n)
{

    memset(dp, -1, sizeof(dp));
    return solve(n);
}