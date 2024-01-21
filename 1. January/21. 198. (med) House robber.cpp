// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[101];

int solve(vi nums, int i)
{
    if (i >= nums.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int take = nums[i] + solve(nums, i + 2);
    int ntake = solve(nums, i + 1);

    return dp[i] = max(take, ntake);
}

int rob(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    return solve(nums, 0);
}

int main()
{
    vi nums{1, 2, 3, 1};
    cout << rob(nums) << endl;
}