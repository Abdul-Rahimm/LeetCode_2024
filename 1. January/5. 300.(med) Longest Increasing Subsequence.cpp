// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;
int dp[2501][2501];
int solve_older(vector<int> &nums, int i, int prev)
{
    if (i >= n) // out of bound
        return 0;

    if (prev != -1 && dp[i][prev] != -1) // index always pos
        return dp[i][prev];

    // take
    int take = 0;
    if (prev == -1 || nums[i] > nums[prev])
        take = 1 + solve(nums, i + 1, i);

    // skip
    int skip = 0;
    skip = solve(nums, i + 1, prev);

    if (prev != -1)
        dp[i][prev] = max(take, skip);

    return max(take, skip);
}

unordered_map<int, int> mp;
int solve(vector<int> nums, int i, int prev, int n)
{
    if (i == n)
        return 0;
    if (mp.find(i) != mp.end())
        return mp[i];

    int take;
    if (nums[i] > prev)
        take = 1 + solve(nums, i + 1, nums[i], n);

    int ntake = solve(nums, i + 1, prev, n);

    return mp[i] = max(take, ntake);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    return solve(nums, 0, INT_MIN, n);
}
