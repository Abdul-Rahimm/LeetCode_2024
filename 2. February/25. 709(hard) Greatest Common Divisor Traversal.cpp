// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
bool canTraverseAllPairs(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (__gcd(nums[i], nums[j]) > 1)
            {
                // make an edge from i to j
                adj[i].push_back(j);
            }
        }
    }

    vector<bool> vis(n, false);

    for (auto pair : adj)
    {
        int u = pair.first;
        vector<int> row = pair.second;

        for (int i : row)
        {
            vis[i] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
            return false;
    }

    return true;
}

int main()
{
    vector<int> nums{2, 3, 6};

    cout << canTraverseAllPairs(nums) << endl;
}