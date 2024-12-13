// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int binarySearch(vi &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int curr = nums[mid];

        if (curr == target)
        {
            return mid;
        }
        else if (curr < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vi nums{1, 3, 5, 8, 9, 15, 20, 30, 35};
    int target = 325;

    int index = binarySearch(nums, target);
    cout << "found at index: " << index << endl;
}