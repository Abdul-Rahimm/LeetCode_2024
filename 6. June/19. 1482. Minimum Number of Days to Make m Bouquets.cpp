// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
int m, k;
void solveBinary(vi &bloom, int start, int end, int &ans)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;
    int count = 0;
    int needed = 0;
    // now check on this mid...do u need more days or less?
    for (int i = 0; i < bloom.size(); i++)
    {
        if (bloom[i] <= mid)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if (count == k)
        {
            needed++;
            count = 0;
        }
    }

    if (needed >= m)
    {
        ans = mid;
        solveBinary(bloom, start, mid, ans);
    }
    else
    {
        solveBinary(bloom, mid + 1, end, ans);
    }
}
int findMax(vi &nums)
{
    int maxValue = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxValue = max(maxValue, nums[i]);
    }
    return maxValue;
}
int minDays(vector<int> &bloomDay, int a, int b)
{
    int n = bloomDay.size();
    m = a, k = b; // global

    int max = findMax(bloomDay);
    int ans = -1; // ans will be stored here
    // now apply binary search on 1...max

    solveBinary(bloomDay, 1, max + 1, ans); // max+1 bec when l==4 it doesnt check if r can actually satisfy

    return ans;
}

int main()
{
    vi nums{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    cout << minDays(nums, 2, 3) << endl;
}