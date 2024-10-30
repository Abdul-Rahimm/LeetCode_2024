// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minimumMountainRemovals(vector<int> &nums)
{
    int n = nums.size();

    vector<int> LIS(n, 1), LDS(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
                LIS[i] = max(LIS[i], LIS[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
                LDS[i] = max(LDS[i], LDS[j] + 1);
        }
    }

    int minRemovals = n;

    for (int i = 0; i < n; i++)
    {
        // length shouuld be atleast 3
        if (LIS[i] > 1 && LDS[i] > 1)
            minRemovals = min(minRemovals, n - LIS[i] - LDS[i] + 1);
    }

    return minRemovals;
}