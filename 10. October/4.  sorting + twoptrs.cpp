// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int maxOperations(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int otherHalf = k - nums[i];

        if (mp.find(otherHalf) != mp.end())
        {
            mp[otherHalf]--;
            if (mp[otherHalf] == 0)
                mp.erase(otherHalf);

            ans++;
        }
        else
        {
            mp[nums[i]]++;
        }
    }

    return ans;
}