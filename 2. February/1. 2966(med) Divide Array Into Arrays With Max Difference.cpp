// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<vector<int>> divideArray(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    vector<vector<int>> ans(n / 3);

    for (int i = 0; i < n / 3; i++)
    {
        int min = nums[i * 3];

        for (int j = i * 3; j < i * 3 + 3; j++)
        {
            if (nums[j] - min > k)
                return {};

            ans[i].push_back(nums[j]);
        }
    }

    return ans;
}