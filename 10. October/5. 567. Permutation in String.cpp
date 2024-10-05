// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool checkInclusion(string s1, string s2)
{
    unordered_map<char, int> mp, copy;

    for (char i : s1)
        mp[i]++;

    copy = mp;

    for (char i : s2)
    {
        if (copy.find(i) != copy.end())
        {
            copy[i]--;

            if (copy[i] == 0)
                copy.erase(i);

            if (copy.size() == 0)
                return true;
        }
        else
        {
            copy = mp;
        }
    }

    return true;
}

int main()
{
    string s1 = "ab", s2 = "eidboaoo";
    cout << checkInclusion(s1, s2) << endl;
    return 0;
}