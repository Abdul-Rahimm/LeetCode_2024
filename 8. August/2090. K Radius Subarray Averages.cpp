// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        if (k == 0)
            return nums;
        if (k > nums.size() / 2)
        {
            vector<int> ans(nums.size(), -1);
            return ans;
        }

        int n = nums.size();
        vector<int> ans(n, 0);

        for (int i = 0, j = n - 1; i < k; i++, j--)
        {

            ans[i] = -1;
            ans[j] = -1;
        }

        int i = 0, j = 0;
        long long sum = 0;

        while (j < n)
        {
            sum += nums[j];

            if (j - i == 2 * k)
            {
                ans[k + i] = sum / (2 * k + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};