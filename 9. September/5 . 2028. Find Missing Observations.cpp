// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> missingRolls(vector<int> &nums, int mean, int n)
{
    vector<int> ans(n);

    // 3 2 4 3
    int numsSize = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    int totalCount = numsSize + n;

    // 2x(nx) = 24(mean*totalCount) - 12(total)

    // 12 + 4x = 21
    // 4x = 9 (3 2 2 2)

    int nx = mean * totalCount - total;

    int div = nx / n;
    int rem = nx % n;

    if ((div >= 6 && rem > 0) || div <= 0 || div > 6)
        return {};

    // ans[0] = div + rem;

    for (int i = 0; i < n; i++)
    {
        ans[i] = div;
        if (rem > 0)
        {
            ans[i] += 1;
            rem--;
        }
    }

    return ans;
}