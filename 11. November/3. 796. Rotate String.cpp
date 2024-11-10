// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool rotateString(string s, string goal)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s == goal)
            return true;

        char temp = s[0];
        for (int j = 0; j < s.size() - 1; j++)
        {
            s[j] = s[j + 1];
        }
        s[s.size() - 1] = temp;
    }

    return false;
}