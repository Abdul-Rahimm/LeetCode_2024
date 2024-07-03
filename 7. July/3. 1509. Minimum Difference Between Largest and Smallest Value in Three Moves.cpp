// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minDifference(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 4)
        return 0;

    sort(nums.begin(), nums.end());

    int first = nums[0];
    int second = nums[n - 1 - 3];

    return second - first;
}

int main()
{
    vi nums{6, 6, 0, 1, 1, 4, 6};
    cout << minDifference(nums) << endl;
}