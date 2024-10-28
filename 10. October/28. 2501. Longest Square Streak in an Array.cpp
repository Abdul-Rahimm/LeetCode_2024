// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[1001][1001];
int solve(int i, int prev, vector<int> &nums)
{
    if (i >= nums.size())
        return 0;
    if (prev != -1 && dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    int take = 0;
    if (prev == -1 || (prev != -1 && nums[prev] * nums[prev] == nums[i]))
    {
        take = 1 + solve(i + 1, i, nums);
    }

    int nottake = solve(i + 1, prev, nums);

    return dp[i][prev + 1] = max(take, nottake);
}

int longestSquareStreak(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    memset(dp, -1, sizeof(dp));

    int ans = solve(0, -1, nums);

    return ans == 1 ? -1 : ans;
}