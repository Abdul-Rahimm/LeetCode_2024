// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int chalang = 0;

        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];

            chalang = max(chalang, curr);
            if (i >= chalang)
            {
                ans++;
            }
        }

        return ans;
    }
};