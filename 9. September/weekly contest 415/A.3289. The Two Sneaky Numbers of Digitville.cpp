// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> getSneakyNumbers(vector<int> &nums)
{
    unordered_map<int, int> mp;
    vector<int> ans;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;

        if (mp[nums[i]] == 2)
        {
            count++;
            ans.push_back(nums[i]);
        }

        if (count == 2)
            return ans;
    }

    return ans;
}