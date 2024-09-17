// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void parse(string s1, unordered_map<string, int> &mp)
{
    int i = 0;
    string word = "";

    while (i <= s1.size())
    {
        if (s1[i] == ' ' || i == s1.size())
        {
            mp[word]++;
            word = "";
        }
        else
        {
            word += s1[i];
        }

        i++;
    }
}

vector<string> uncommonFromSentences(string s1, string s2)
{
    unordered_map<string, int> mp;
    vector<string> ans;

    parse(s1, mp);
    parse(s2, mp);

    for (auto pair : mp)
    {
        if (pair.second == 1)
            ans.push_back(pair.first);
    }

    return ans;
}