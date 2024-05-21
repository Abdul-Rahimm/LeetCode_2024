// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &curr, int i, vector<int> &nums)
    {
        if (i >= nums.size())
        {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(ans, curr, i + 1, nums);
        curr.pop_back();
        solve(ans, curr, i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(ans, current, 0, nums);

        return ans;
    }
};