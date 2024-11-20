// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> vis((*max_element(nums.begin(), nums.end())) + 1, 0);
    int ans = 0;
    bool status = true;
    int count_one = 0;
    int sum = 0;

    // first window
    for (int i = 0; i < k; i++)
    {
        vis[nums[i]]++;
        sum += nums[i];

        if (vis[nums[i]] > 1)
        {
            status = false;
            count_one++;
        }
    }
    if (count_one == 0)
        ans = max(ans, sum);

    for (int i = k, j = 0; i < n; i++)
    {
        // j is for window shrink
        sum -= nums[j];
        if (vis[nums[j]] > 1)
        {
            count_one--;

            if (count_one == 0)
                status = true;
        }
        vis[nums[j]]--; // mark unvisited
        j++;            // shrink

        // now time to expand
        vis[nums[i]]++;
        sum += nums[i];

        if (vis[nums[i]] > 1)
        {
            status = false;
            count_one++;
        }

        if (status)
            ans = max(ans, sum);
    }

    return ans;
}

int main()
{
    vi nums{1, 5, 4, 2, 9, 9, 9};
    cout << maximumSubarraySum(nums, 3) << endl;
}
