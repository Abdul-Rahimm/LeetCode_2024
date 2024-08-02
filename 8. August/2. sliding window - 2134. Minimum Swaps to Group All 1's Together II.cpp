// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        nums.push_back(nums[i]);
    }

    int totalOnes = 0;

    for (int i = 0; i < n; i++)
    {
        totalOnes += nums[i];
    }

    // make a window of size totalOnes

    int count = 0;
    for (int i = 0; i < totalOnes; i++)
    {
        count += nums[i];
    }

    int swaps = totalOnes - count;
    for (int i = totalOnes; i < 2 * n; i++)
    {
        count -= nums[i - totalOnes];
        count += nums[i];

        swaps = min(swaps, totalOnes - count);
    }

    return swaps;
}