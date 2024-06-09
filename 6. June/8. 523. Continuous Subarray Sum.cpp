// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool solve(int i, vi &nums, int k, int sum)
{
    if (i >= nums.size())
        return false;

    if (sum % k == 0)
        return true;

    bool take = solve(i + 1, nums, k, sum + nums[i]);
    bool nottake = solve(i + 1, nums, k, sum);

    return take | nottake;
}

bool checkSubarraySum_notAC(vector<int> &nums, int k)
{
    int n = nums.size();

    return solve(0, nums, k, 0);
}

bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp; // rem --> index

    mp[0] = -1;

    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];
        int mod = sum % k;

        if (mp.find(mod) == mp.end())
        {
            // rem not found in map
            mp[mod] = i;
        }
        else
        {
            // remainder found in map
            // calculate length of subarray
            if (i - mp[mod] >= 2)
                return true;
        }
    }

    return false;
}

int main()
{
    vi nums{23, 2, 6, 4, 7};
    cout << checkSubarraySum(nums, 13) << endl;
}