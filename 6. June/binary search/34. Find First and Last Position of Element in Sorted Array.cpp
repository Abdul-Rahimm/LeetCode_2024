// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void searchMinValue(vector<int> &nums, int target, int l, int r, int &minValue)
{
    int mid = l + (r - l) / 2;

    if (l >= r)
    {
        if (nums[mid] == target)
        {
            minValue = mid;
        }
        return;
    }

    if (nums[mid] == target)
    {
        minValue = mid;
        searchMinValue(nums, target, l, mid - 1, minValue);
    }
    else if (nums[mid] < target)
    {
        searchMinValue(nums, target, mid + 1, r, minValue);
    }
    else
    {
        searchMinValue(nums, target, l, mid - 1, minValue);
    }
}
void searchMaxValue(vector<int> &nums, int target, int l, int r, int &maxValue)
{

    int mid = l + (r - l) / 2;
    if (l >= r)
    {
        if (nums[mid] == target)
        {
            maxValue = mid;
        }
        return;
    }

    if (nums[mid] == target)
    {
        maxValue = mid;
        searchMaxValue(nums, target, mid + 1, r, maxValue);
    }
    else if (nums[mid] < target)
    {
        searchMaxValue(nums, target, mid + 1, r, maxValue);
    }
    else
    {
        searchMaxValue(nums, target, l, mid - 1, maxValue);
    }
}

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty() || (target < nums[0]) || target > nums[nums.size() - 1])
        return {-1, -1};

    int l = 0, r = nums.size() - 1;

    int minValue = -1;
    searchMinValue(nums, target, l, r, minValue);
    int maxValue = -1;
    searchMaxValue(nums, target, l, r, maxValue);

    return {minValue, maxValue};
}

int main()
{
    vi range{5, 7, 7, 8, 8, 10};
    vi ans = searchRange(range, 8);
    print(ans);
}