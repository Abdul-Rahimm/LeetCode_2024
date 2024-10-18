// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int largestCombination(vector<int> &nums)
{
    int highestBits = 0;
    int mx = INT_MIN;

    while (mx != 0)
    {
        int currentBits = 0;
        mx = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];

            if (curr & 1 == 1)
                currentBits++;

            nums[i] = nums[i] >> 1;
            mx = max(mx, nums[i]);
        }
        cout << mx << endl;
        highestBits = max(highestBits, currentBits);
    }

    return highestBits;
}