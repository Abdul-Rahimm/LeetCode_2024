// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[50001][50001];
int solve(int i, int j, vector<int> &nums)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (nums[i] <= nums[j])
        return dp[i][j] = j - i;

    int inc_i = solve(i + 1, j, nums);
    int dec_j = solve(i, j - 1, nums);

    return dp[i][j] = max(inc_i, dec_j);
}

int maxWidthRamp(vector<int> &nums)
{
    for (int i = 0; i < 50001; i++)
    {
        for (int j = 0; j < 50001; j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = solve(0, nums.size() - 1, nums);
    return ans;
}

int main()
{
    vi nums{6, 0, 8, 2, 1, 5};
    cout << maxWidthRamp(nums) << endl; // Output: 4
    return 0;
}