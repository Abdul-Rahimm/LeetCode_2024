// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;
int dp[501];

int solve(int i, int k, vector<int> &arr)
{
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int currMax = -1;
    int result = 0;

    for (int j = i; j < n && j - i + 1 <= k; j++)
    {
        currMax = max(currMax, arr[j]);

        result = max(result, (j - i + 1) * currMax + solve(j + 1, k, arr));
    }

    return dp[i] = result;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    n = arr.size();
    memset(dp, -1, sizeof(dp));

    return solve(0, k, arr);
}