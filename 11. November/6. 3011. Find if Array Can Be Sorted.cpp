// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

//   64 32 16 8 4 2 1
// 75 1  0  0  1 0 1 1 = 4
// 34 0  1  0  0 0 1 0 = 2
// 30 0  0  1  1 1 1 0 = 4
void swap(int i, vector<int> &nums)
{
    int temp = nums[i];
    nums[i] = nums[i + 1];
    nums[i + 1] = temp;
}

bool canSortArray(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
                    swap(j, nums);
                else
                    return false;
            }
        }
    }

    return true;
}