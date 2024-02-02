// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string greatestLetter(string s)
{
    map<char, int> mp;

    for (char i : s)
    {
        if (int(i) >= 97 && mp[tolower(i)] % 2 == 0)
            mp[tolower(i)]++;
        else if (int(i) < 97 && mp[tolower(i)] < 10000)
            mp[tolower(i)] += 10000;
    }

    char c;
    bool status = false;

    for (auto pair : mp)
    {
        if (pair.second == 10001)
        {
            c = pair.first;
            status = true;
        }
    }

    string ans = "";
    ans += toupper(c);

    if (status)
        return ans;

    return "";
}