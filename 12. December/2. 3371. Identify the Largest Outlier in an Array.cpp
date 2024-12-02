// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int getLargestOutlier(vector<int> &nums)
{
    // sort(nums.begin(), nums.end());
    unordered_map<int, int> mp;
    int total = 0;

    for (int i : nums)
    {
        mp[i]++;
        total += i;
    }

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        cout << total << " -= " << nums[i];
        total -= nums[i];

        if (total % 2 == 0)
        {
            if (mp.find(total / 2) != mp.end())
            {
                return nums[i];
            }
        }

        total += nums[i];
    }

    return -1;
}
int main()
{
    vi nums{-2, -1, -3, -6, 4};
    cout << getLargestOutlier(nums) << endl;
}