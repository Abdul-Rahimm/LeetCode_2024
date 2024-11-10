// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minChanges(string s)
{
    char curr = s[0];

    int count = 0;
    int changes = 0;
    int n = s.length();

    // Iterate through each character in the string
    for (int i = 0; i < n; i++)
    {

        if (s[i] == curr)
        {
            count++;
            continue;
        }

        if (count % 2 == 0)
        { // Even
            count = 1;
        }
        else
        { // Odd
            count = 0;
            changes++;
        }

        curr = s[i];
    }

    return changes;
}