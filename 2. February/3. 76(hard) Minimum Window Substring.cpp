// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

unordered_map<char, int> mp;

string minWindow(string s, string t)
{
    int n = s.size();

    if (t.size() > n)
        return "";

    for (char ch : t)
        mp[ch]++;

    int requiredCount = t.size();
    int minWindowSize = INT_MAX;
    int i = 0, j = 0;
    int start_i = 0;

    while (j < n)
    {

        char ch = s[j];

        // this character was in t
        if (mp[ch] > 0)
            requiredCount--;

        mp[ch]--;

        while (requiredCount == 0)
        {
            // start shrinking the window

            int currWindowSize = j - i + 1;

            if (currWindowSize < minWindowSize)
            {
                minWindowSize = currWindowSize;
                start_i = i;
            }

            mp[s[i]]++;

            if (mp[s[i]] > 0)
                requiredCount++;

            i++;
        }

        j++;
    }

    return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
}