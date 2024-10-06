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
    unordered_map<char, int> mp, loop;

    for (char i : p)
        mp[i]++;

    vector<int> ans;

    int i = 0;
    int j = 0;

    while (j < n)
    {
        loop[s[j]]++;

        if (j - i + 1 > m)
        {
            loop[s[i]]--;
            if (loop[s[i]] == 0)
                loop.erase(s[i]);
            i++;
        }

        if (mp == loop)
            ans.push_back(i);

        j++;
    }

    return ans;
}