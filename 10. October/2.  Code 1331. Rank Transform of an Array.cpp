// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> arrayRankTransform(vector<int> &nums)
{
    set<int> st(nums.begin(), nums.end()); // sorts and removes duplicates behtereen

    unordered_map<int, int> mp;
    int count = 1;

    for (auto i : st)
    {
        mp[i] = count;
        count++;
    }

    // in place change the nums. no need for extra array copy
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = mp[nums[i]];
    }

    return nums;
}