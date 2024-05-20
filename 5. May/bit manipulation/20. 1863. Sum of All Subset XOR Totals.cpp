// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int solve(vector<int> nums, int i, int Xor)
{

    if (i >= nums.size())
        return Xor;

    int include = solve(nums, i + 1, Xor ^ nums[i]);
    int exclude = solve(nums, i + 1, Xor);

    return include + exclude;
}

int subsetXORSum(vector<int> &nums)
{
    return solve(nums, 0, 0);
}