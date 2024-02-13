// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;

        if (mp[nums[i]] > n / 2)
            return nums[i];
    }

    return 0;
}