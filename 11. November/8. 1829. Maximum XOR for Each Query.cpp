// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    int n = nums.size();
    int xorr = nums[0];
    int maxxorr = pow(2, maximumBit) - 1;

    for (int i = 1; i < n; i++)
        xorr ^= nums[i];

    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = xorr ^ maxxorr;
        xorr ^= nums[n - 1 - i];
    }

    return ans;
}