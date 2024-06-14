// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minIncrementForUnique(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int min = nums[0];
    int count = 0;

    for (int i = 1; i < nums.size(); i++)
    {

        min = max(nums[i], min + 1);

        if (nums[i] <= min)
        {
            count += min - nums[i];
        }
    }

    return count;
}
int main()
{

    vi nums{1, 2, 2};
    cout << minIncrementForUnique(nums) << endl;
}