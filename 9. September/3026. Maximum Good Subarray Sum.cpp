// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef long long ll;

typedef pair<int, int> P;
//         j                 i
// (-1,0) (2,2) (3,1) (4,3) (5,4)
long long maximumSubarraySum(vector<int> &nums, int k)
{

    int n = nums.size();
    vector<ll> prefixSum(n, 0);
    prefixSum[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefixSum[i] += prefixSum[i - 1] + nums[i];
    }

    unordered_map<ll, ll> mp;
    mp[nums[0]] = 0;

    ll ans = -1e15;

    for (int j = 1; j < n; j++)
    {
        int exp1 = nums[j] + k;
        int exp2 = nums[j] - k;

        if (mp.find(exp1) != mp.end())
        {
            ans = max(ans, prefixSum[j] - mp[exp1]);
        }

        if (mp.find(exp2) != mp.end())
        {
            ans = max(ans, prefixSum[j] - mp[exp2]);
        }

        if (mp.find(nums[j]) != mp.end())
            mp[nums[j]] = min(mp[nums[j]], prefixSum[j - 1]);
        else
            mp[nums[j]] = prefixSum[j - 1];
    }

    return (ans == -1e15 ? 0 : ans);
}
long long maximumSubarraySum(vector<int> &nums, int k)
{

    int n = nums.size();
    vector<P> indexes;

    for (int i = 0; i < n; i++)
    {
        P current = {nums[i], i};
        indexes.push_back(current);
    }

    sort(indexes.begin(), indexes.end());

    int i = n - 1;
    int j = i - 1;

    while (i >= 0)
    {

        while (abs(indexes[i].first - indexes[j].first) < k)
            j--;

        if (abs(indexes[i].first - indexes[j].first) == k)
        {
            int rangeBegin =
        }
    }
}
int main()
{
    vi nums{-1, 3, 2, 4, 5};
    int k = 3;

    long long answer = maximumSubarraySum(nums, k);
}