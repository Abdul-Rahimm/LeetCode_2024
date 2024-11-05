// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minChanges(string s)
{
    int changes = 0;
    int n = s.length();

    for (int i = 0; i < n; i += 2)
    {

        if (s[i] != s[i + 1])
        {
            changes++;
        }
    }

    return changes;
}