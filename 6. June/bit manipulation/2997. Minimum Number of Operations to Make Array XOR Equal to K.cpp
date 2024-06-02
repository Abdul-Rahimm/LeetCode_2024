// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

// int totalXor = 0;
// for (int i : nums)
//     totalXor ^= i;
// int diff = totalXor ^ k;
// return __builtin_popcount(diff);

int minOperations(vector<int> &nums, int k)
{
    bool status = true;
    int flips = 0;

    while (status == true)
    {

        status = false;
        int currentBit = 0;
        for (int i = 0; i < nums.size(); i++)
        {

            currentBit ^= nums[i] & 1;
            if (nums[i] > 0)
                status = true; // keep the loop continue;

            nums[i] >>= 1;
        }

        if (currentBit != (k & 1))
            flips++;

        k >>= 1;

        if (status == false && k > 0)
            status = true;
    }

    return flips;
}
int main()
{
    vector<int> nums{4};
    cout << minOperations(nums, 7) << endl;
}