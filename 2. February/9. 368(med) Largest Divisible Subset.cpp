// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    vector<int> row;

    for (int i = 0; i < n; i++)
    {
        row.push_back(nums[i]); // initial take

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] % nums[j - 1] == 0 || nums[j - 1] % nums[j] == 0)
                row.push_back(nums[j]);
        }

        if (row.size() > ans.size())
            ans = row;

        row.clear();
    }

    return ans;
}

// learned the bottom up approach from MIK
vector<int> largestDivisibleSubset_MIK(vector<int> &nums)
{
    // if(nums.size() == 1)
    //     return {nums[0]};

    sort(nums.begin(), nums.end());

    int n = nums.size();
    int maxL = 1;
    int last_chosen_index = 0;

    vector<int> dp(n, 1);
    vector<int> prev_idx(n, -1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (nums[i] % nums[j] == 0)
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    prev_idx[i] = j;
                }
            }

            if (dp[i] > maxL)
            {
                maxL = dp[i];
                last_chosen_index = i;
            }
        }
    }

    vector<int> ans;
    while (last_chosen_index != -1)
    {
        ans.push_back(nums[last_chosen_index]);
        last_chosen_index = prev_idx[last_chosen_index];
    }

    return ans;
}
int main()
{
    vi nums{3, 4, 16, 8};
}