// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minPatches(vector<int> &nums, int limit)
{
    int n = nums.size();
    int maxReach = 0;
    int patch = 0;

    for (int i = 0; i < n; i++)
    {
        if (maxReach == limit)
            return patch;

        if (nums[i] <= maxReach + 1)
        {
            maxReach += nums[i];
        }
        else
        {
            patch++;
            maxReach += maxReach + 1;
            i--;
        }
    }

    while (maxReach < limit)
    {
        maxReach += maxReach + 1;
        patch++;
    }

    return patch;
}

int main()
{
    vi nums{1, 7, 21, 31, 34, 37, 40, 43, 49, 87, 90, 92, 93, 98, 99};
    int answer = minPatches(nums, 12);
    cout << answer << endl;
}