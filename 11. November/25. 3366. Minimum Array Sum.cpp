// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int n;
    int dp[101][101][101];

    int solve(vector<int> &nums, int k, int op1, int op2, int i)
    {
        if (i >= n)
            return 0;
        if (dp[op1][op2][i] != -1)
            return dp[op1][op2][i];

        int result = INT_MAX;

        if (op1 > 0)
        {
            int operation1 = (nums[i] + 1) / 2;
            result =
                min(result, operation1 + solve(nums, k, op1 - 1, op2, i + 1));
        }

        if (op2 > 0 && nums[i] >= k)
        {
            int operation2 = nums[i] - k;
            result =
                min(result, operation2 + solve(nums, k, op1, op2 - 1, i + 1));
        }

        if (op1 > 0 && op2 > 0)
        {
            int operation_12 = (nums[i] + 1) / 2;

            if (operation_12 >= k)
            {
                operation_12 -= k;
                result = min(result, operation_12 + solve(nums, k, op1 - 1,
                                                          op2 - 1, i + 1));
            }

            if (nums[i] >= k)
            {
                int operation_21 = nums[i] - k;
                operation_21 = (operation_21 + 1) / 2;
                result = min(result, operation_21 + solve(nums, k, op1 - 1,
                                                          op2 - 1, i + 1));
            }
        }

        result = min(result, nums[i] + solve(nums, k, op1, op2, i + 1));

        return dp[op1][op2][i] = result;
    }
    int minArraySum(vector<int> &nums, int k, int op1, int op2)
    {
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, k, op1, op2, 0);
    }
};
