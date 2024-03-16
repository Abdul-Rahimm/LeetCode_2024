// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;

    unordered_map<int, int> mp;
    int currSum = 0;
    int maxL = 0;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {

        currSum += (nums[i] == 1) ? 1 : -1;

        if (mp.find(currSum) != mp.end())
        {
            maxL = max(maxL, i - mp[currSum]);
        }
        else
            mp[currSum] = i;
    }

    return maxL;
}