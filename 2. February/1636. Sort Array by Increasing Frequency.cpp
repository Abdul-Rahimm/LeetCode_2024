// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> P;

vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int, int> mp;
    priority_queue<P, vector<P>, greater<P>> pq;
    vi ans;

    for (int i : nums)
        mp[i]++;

    for (auto pair : mp)
        pq.push({pair.second, pair.first});

    while (!pq.empty())
    {
        int freq = pq.top().first;
        int num = pq.top().second;
        pq.pop();

        for (int i = 0; i < freq; i++)
            ans.push_back(num);
    }

    return ans;
}
