// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> targetIndices(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int index;

    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {

        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
        {
            index = mid;
        }

        if (nums[mid] >= target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    vector<int> ans;
    while (nums[index] == target)
    {
        ans.push_back(index);
        index++;
    }

    return ans;
}

int main()
{
    vi nums{1, 2, 5, 2, 3};
    vector<int> ans = targetIndices(nums, 2);
}