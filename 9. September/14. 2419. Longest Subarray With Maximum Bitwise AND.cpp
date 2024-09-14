// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int longestSubarray(vector<int> &nums)
{
    int maxVal = 0;
    int ans = 0;
    int streak = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxVal)
        {
            maxVal = nums[i];
            streak = 0;
            ans = 0;
        }

        if (nums[i] == maxVal)
            streak++;
        else
            streak = 0;

        ans = max(ans, streak);
    }

    return ans;
}