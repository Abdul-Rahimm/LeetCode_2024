// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, char> P;

string frequencySort(string s)
{
    unordered_map<char, int> mp;
    priority_queue<P> pq;
    string ans;

    for (char i : s)
        mp[i]++;

    for (auto pair : mp)
        pq.push({pair.second, pair.first});

    while (!pq.empty())
    {
        int freq = pq.top().first;
        char ch = pq.top().second;

        for (int i = 0; i < freq; i++)
        {
            ans.push_back(ch);
        }

        pq.pop();
    }

    return ans;
}

int main()
{
    string s = "bbaAcccc";
    // cin >> s;

    cout << frequencySort(s) << endl;
}