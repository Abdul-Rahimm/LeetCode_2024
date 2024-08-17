// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long maximumSubarraySum(vector<int> &nums, int k)
{

    vector<int> present(100001, 0);
    vector<long long> prefixSum(1, 0);

    int n = nums.size();
    int trues = 0;
    long long ans = 0;

    // prefix Sum to calculate the sum in constant time
    for (int i = 0, sum = 0; i < n; i++)
    {
        sum += nums[i];
        prefixSum.push_back(sum);
    }

    for (int i = 0; i < k; i++)
    {
        int current = nums[i];

        // check if it has been seen before in the window
        if (present[current] == 0)
        {
            trues++;
        }

        present[current]++;
    }

    int j = k, i = 1;
    // start the sliding window process

    while (j < n)
    {

        if (trues == k)
            ans = max(ans, prefixSum[j] - prefixSum[j - k]);

                present[nums[i - 1]]--;

        if (present[nums[i - 1]] == 0)
            trues--;

        present[nums[j]]++;
        if (present[nums[j]] == 1)
            trues++;

        i++;
        j++;
    }

    return ans;
}

int main()
{
    vector<int> nums{1, 5, 4, 2, 9, 9, 9};
    long long ans = maximumSubarraySum(nums, 3);
}