// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = 0;

    int current = 0;
    int i = 0;
    int j = 0;

    while (j < n)
    {
        current += nums[j];

        while (current > k)
        {
            current -= nums[i];
            i++;
        }
        if (current == k)
            ans++;

        j++;
    }

    return ans;
}

int main()
{
    vi nums{1, 2, 3};
    int ans = subarraySum(nums, 3);
    cout << ans << endl;
}