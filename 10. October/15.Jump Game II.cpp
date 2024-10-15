// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int solve(int i, int current, vector<int> nums)
{
    if (i >= nums.size())
        return 0;
    if (current >= nums.size())
        return 1;

    int take = 1 + solve(i + 1, current + nums[i], nums);
    int ntake = solve(i + 1, current, nums);

    return min(take, ntake);
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    return solve(0, 0, nums);
}

int main()
{
    vi nums{2, 3, 1, 1, 4};
    cout << jump(nums) << endl; // Output: 2
    return 0;
}