// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int MOD = 1e9 + 7;
int dp[1001][1001];

int solve(int n, int k)
{
    if (n == 0)
        return 0;

    if (k == 0)
        return 1;

    if (dp[n][k] != -1)
        return dp[n][k];

    int result = 0;
    for (int inv = 0; inv <= min(n - 1, k); inv++)
    {

        // i have k inversions. need k more inversions
        result = (result % MOD + solve(n - 1, k - inv) % MOD) % MOD;
    }

    return dp[n][k] = result;
}

int kInversePairs(int n, int k)
{
    memset(dp, -1, sizeof(dp));

    return solve(n, k);
}