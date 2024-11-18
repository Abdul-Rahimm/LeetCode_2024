// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> decrypt(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans(n, 0);

    if (k == 0)
    {
        return ans;
    }
    if (k < 0)
        reverse(nums.begin(), nums.end());

    vector<int> prefixSum = nums;
    for (int i : nums)
        prefixSum.push_back(i);
    for (int i = 1; i < prefixSum.size(); i++)
        prefixSum[i] = prefixSum[i - 1] + prefixSum[i];

    if (k > 0)
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefixSum[i + k] - prefixSum[i];
        }
    else
        for (int i = 0; i < n; i++)
        {
            int index = n - i - k - 1;
            ans[i] = prefixSum[index] - prefixSum[index + k];
        }

    return ans;
}