// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long findScore(vector<int> &nums)
{
    int n = nums.size();
    long long score = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
        pq.push({nums[i], i});

    vector<bool> visited(n, false);

    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        int val = curr.first;
        int index = curr.second;

        if (visited[index])
            continue;

        score += val;

        visited[index] = true;
        if (index > 0)
            visited[index - 1] = true;
        if (index < n - 1)
            visited[index + 1] = true;
    }

    return score;
}

int main()
{

    vi nums{2, 1, 3, 4, 5, 2};
    cout << findScore(nums) << endl;
}