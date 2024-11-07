// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int largestCombination(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    bool status = false;

    for (int i = 0; status == false; i++)
    {
        int ones = 0;
        status = true;

        for (int j = 0; j < n; j++)
        {
            int curr = nums[j];
            ones += (curr & 1);
            nums[j] >>= 1;

            if (nums[j] > 0)
                status = false;
        }

        ans = max(ans, ones);
    }

    return ans;
}

int main()
{
    vi nums{8, 8};
    cout << largestCombination(nums) << endl;
}