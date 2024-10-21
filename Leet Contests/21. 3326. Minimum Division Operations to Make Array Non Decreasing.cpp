// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    bool even = false;

    for (int i = 1; i < n; i++)
    {

        if (nums[i - 1] == nums[i])
            continue;

        if (nums[i] % 2 == 0)
        {
            nums[i] = 2;
            even = true;
        }
        else if (even)
        {
            return -1;
        }
        else
        {
            int div = 3;
            int copy = nums[i];

            while (div <= copy / 2)
            {
                if (copy % div != 0)
                {
                    div += 2;
                }
                else
                {
                    nums[i] = div;
                    break;
                }
            }
        }

        if (nums[i] < nums[i - 1])
        {
            return -1;
        }
        else
            ans++;
    }

    for (int i : nums)
        cout << i << " ";
    cout << endl;

    return ans;
}

int main()
{
    vi nums = {25, 7};
    int ans = minOperations(nums);
    cout << ans << endl; // Output: 3
}