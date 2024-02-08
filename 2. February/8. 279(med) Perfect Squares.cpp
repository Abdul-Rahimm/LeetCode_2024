// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
int dp[10001];

int solve(int n)
{

    if (dp[n] != -1)
        return dp[n];

    if (n == 0)
        return 0;

    int minCount = INT_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        int result = 1 + solve(n - (i * i));

        minCount = min(minCount, result);
    }

    return dp[n] = minCount;
}

int numSquares(int n)
{

    memset(dp, -1, sizeof(dp));
    return solve(n);
}

int main()
{
    vi nums{5};

    for (int i : nums)
    {
        cout << numSquares(i) << endl;
    }
}