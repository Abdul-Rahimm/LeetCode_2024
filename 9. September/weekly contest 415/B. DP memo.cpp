// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long dp[5][100001];

long long solve(int i, int j, vector<int> &a, vector<int> &b, int n)
{

    if (i == 4)
        return 0;
    if (j >= n)
        return -1e11;
    if (dp[i][j] != -1e11)
        return dp[i][j];

    long long take = (long long)a[i] * b[j] + solve(i + 1, j + 1, a, b, n);
    long long ntake = solve(i, j + 1, a, b, n);

    if (take > ntake)
        return dp[i][j] = take;

    return dp[i][j] = ntake;
}

long long maxScore(vector<int> &a, vector<int> &b)
{
    int n = b.size();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 100001; j++)
            dp[i][j] = -1e11;
    }
    long long ans = solve(0, 0, a, b, n);
    return ans;
}