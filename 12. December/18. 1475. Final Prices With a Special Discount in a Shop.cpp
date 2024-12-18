// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans = nums;

        for (int i = n - 2; i >= 0; i--)
        {
            int curr = nums[i];

            int j = i + 1;
            while (j < n && nums[j] > curr)
            {
                j++;
            }

            if (j != n)
            {
                ans[i] -= nums[j];
            }
        }

        return ans;
    }
};