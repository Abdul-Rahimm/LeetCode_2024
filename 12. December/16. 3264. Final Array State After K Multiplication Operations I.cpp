// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int mul)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        while (k--)
        {
            auto curr = pq.top();
            pq.pop();

            int val = curr.first * mul;
            int idx = curr.second;

            nums[idx] = val;
            pq.push({val, idx});
        }

        return nums;
    }
};