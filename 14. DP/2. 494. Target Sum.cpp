// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[21][2002];
int solve(int i, int curr, vector<int> &nums, int target)
{
    if (dp[i][curr] != -1)
        return dp[i][curr];
    if (i == nums.size() && curr != target)
        return dp[i][curr] = 0;
    if (i == nums.size() && curr == target)
        return dp[i][curr] = 1;

    int pos = solve(i + 1, curr + nums[i], nums, target);
    int neg = solve(i + 1, curr - nums[i], nums, target);

    return dp[i][curr] = pos + neg;
}

int findTargetSumWays(vector<int> &nums, int target)
{
    memset(dp, -1, sizeof(dp));
    return solve(0, 1000, nums, target + 1000);
}
