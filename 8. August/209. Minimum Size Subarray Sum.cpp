// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minSubArrayLen(int target, vector<int> &nums)
{

    int n = nums.size();
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;

    while (j < n)
    {

        sum += nums[j];

        if (sum >= target)
        {
            while (sum >= target)
            {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        j++;
    }

    return ans == INT_MAX ? 0 : ans;
}