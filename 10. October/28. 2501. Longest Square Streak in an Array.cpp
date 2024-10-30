// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int longestSquareStreak(vector<int> &nums)
{
    unordered_set<long long> st(nums.begin(), nums.end());
    int ans = 0;

    for (int i : nums)
    {
        int streak = 1;
        long long current = i;

        while (true)
        {
            long long sq = current * current;

            if (st.find(sq) != st.end())
            {
                current = sq;
                streak++;
            }
            else
                break;
        }
        ans = max(ans, streak);
    }

    return ans == 1 ? -1 : ans;
}