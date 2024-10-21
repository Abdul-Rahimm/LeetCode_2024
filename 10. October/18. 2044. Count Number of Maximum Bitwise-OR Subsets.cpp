// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int solve(vector<int> &nums, int i, int current, int allXor, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (dp[i][current] != -1)
        return dp[i][current];
    if (i == n && current == allXor)
        return 1;
    if (i == n && current != allXor)
        return 0;

    int take = solve(nums, i + 1, current | nums[i], allXor, dp);
    int nottake = solve(nums, i + 1, current, allXor, dp);

    return dp[i][current] = take + nottake;
}
int countMaxOrSubsets(vector<int> &nums)
{
    int allXor = 0;
    int n = nums.size();
    int ans = 0;

    for (int i : nums)
    {
        allXor |= i;
    }
    vector<vector<int>> dp(n + 1, vector<int>(allXor + 1, -1));

    ans = solve(nums, 0, 0, allXor, dp);

    return ans;
}