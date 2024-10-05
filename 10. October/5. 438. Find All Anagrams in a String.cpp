// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> findAnagrams(string s, string p)
{
    int n = s.length();
    int m = p.length();
    sort(p.begin(), p.end());

    vector<int> ans;

    for (int i = 0; i <= n - m; i++)
    {
        string curr = s.substr(i, m);
        sort(curr.begin(), curr.end());

        if (curr == p)
            ans.push_back(i);
    }

    return ans;
}