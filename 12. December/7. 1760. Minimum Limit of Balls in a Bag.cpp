// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    bool isPossible(int mid, vector<int> &nums, int mx)
    {
        int operations = 0;

        for (int i : nums)
        {
            int ops = ceil(i / (double)mid) - 1;
            operations += ops;

            if (operations > mx)
                return false;
        }

        return true;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int left = 1;
        int right = 1;

        for (int i : nums)
            right = max(right, i);

        while (left < right)
        {
            int mid = (left + right) / 2;

            if (isPossible(mid, nums, maxOperations))
            {
                // look for smaller penalty
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return right;
    }
};