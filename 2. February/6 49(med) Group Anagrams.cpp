// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;

    for (string str : strs)
    {

        string copy = str; // just to save the original string
        sort(str.begin(), str.end());

        mp[str].push_back(copy); // pushing back the original word
    }

    for (auto pair : mp)
    {
        string key = pair.first;
        vector<string> val = pair.second;

        ans.push_back(val);
    }

    return ans;
}