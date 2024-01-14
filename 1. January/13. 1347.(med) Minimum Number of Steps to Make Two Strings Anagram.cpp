// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minSteps(string s, string t)
{
    unordered_map<char, int> mp1, mp2;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        mp1[s[i]]++;
        mp2[t[i]]++;
    }

    int count = 0;
    for (auto &[c, freq] : mp2)
    {
        if (mp1.find(c) != mp1.end())
        {
            count += abs(mp1[c] - mp2[c]);
        }
        else
            count += mp2[c];
    }

    return count;
}

int minSteps_MIK(string s, string t)
{
    int n = s.length();

    int mp_s[26] = {0};
    int mp_t[26] = {0};

    for (int i = 0; i < n; i++)
    {
        mp_s[s[i] - 'a']++;
        mp_t[t[i] - 'a']++;
    }

    int result = 0;

    for (int i = 0; i < 26; i++)
    {
        int freq_in_t = mp_t[i];

        int freq_in_s = mp_s[i];

        if (freq_in_t < freq_in_s)
        {
            result += freq_in_s - freq_in_t;
        }
    }

    return result;
}