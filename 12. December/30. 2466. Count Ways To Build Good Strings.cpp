// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int mod = 1e9 + 7;
    int low, high, zero, one;
    int dp[100011];

    int solve(int sz)
    {
        if (sz == high)
        {
            return dp[sz] = 1;
        }
        else if (sz > high)
        {
            return 0;
        }

        if (dp[sz] != -1)
            return dp[sz];

        int takeZero = solve(sz + zero) % mod;
        int takeOne = solve(sz + one) % mod;

        return dp[sz] = ((sz >= low && sz < high) + (takeZero + takeOne)) % mod;
    }

    int countGoodStrings(int l, int h, int z, int o)
    {
        low = l;
        high = h;
        zero = z;
        one = o;

        string s;
        memset(dp, -1, sizeof(dp));
        return solve(0);
    }
};
