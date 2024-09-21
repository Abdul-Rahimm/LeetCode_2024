// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string shortestPalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    int i = 0;

    while (i < s.length())
    {

        if (memcmp(s.c_str(), rev.c_str() + i, s.length() - i) == 0)
            return rev.substr(0, i) + s;

        i++;
    }

    return "";
}