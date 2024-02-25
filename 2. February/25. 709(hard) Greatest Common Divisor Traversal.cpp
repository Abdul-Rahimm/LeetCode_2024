// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
unordered_map<int, vector<int>> adj;
int n;

bool BFS(int start, vector<bool> vis)
{
    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        vis[front] = true;

        for (int i : adj[front])
        {
            if (!vis[i])
                q.push(i);
        }
    }

    for (int i = 0; i < n; i++)
        if (vis[i] == false)
            return false;

    return true;
}

bool canTraverseAllPairs(vector<int> &nums)
{
    if (nums.size() == 1)
        return true;

    n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (__gcd(nums[i], nums[j]) > 1)
            {
                // make an edge from i to j
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (BFS(i, vis))
            return true;
    }

    return false;
}
int main()
{
    vector<int> nums{2, 3, 6};

    cout << canTraverseAllPairs(nums) << endl;
}