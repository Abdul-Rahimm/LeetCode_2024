// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
int n;

int solve(vector<int> nums, int i, int count, int difference, int prev)
{
    if (i >= n)
        return 0;

    int take;

    //         if(count == 0 || difference == INT_MIN || prev != -1 && nums[i] - nums[prev] == difference){

    //             int length_3;
    //             length_3 = count == 3 ? 1 : 0 ;

    //             take = length_3 + solve(nums, i+1. count+1, nums[i]-nums[prev], nums[i]);
    //         }

    int ntake = solve(nums, i + 1. count, difference, prev);
}

int numberOfArithmeticSlices(vector<int> &nums)
{
    n = nums.size();

    return solve(nums, 0, 0, INT_MIN, -1);
}

int numberOfArithmeticSlices_MIK(vector<int> &nums)
{
    n = nums.size();

    int result = 0;

    vector<unordered_map<long, int>> mp(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long diff = (long)nums[i] - nums[j];

            auto it = mp[j].find(diff);

            int count_at_j = it == mp[j].end() ? 0 : it->second; // count at j for difference = diff

            mp[i][diff] += count_at_j + 1;

            result += count_at_j;
        }
    }

    return result;
}