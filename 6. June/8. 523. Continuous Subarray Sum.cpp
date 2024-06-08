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

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    return solve(0, nums, k, 0);
}

int main()
{
    vi nums{23, 2, 4, 6, 7};
    cout << checkSubarraySum(nums, 6) << endl;
}